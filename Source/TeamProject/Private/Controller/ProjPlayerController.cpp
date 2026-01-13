// Fill out your copyright notice in the Description page of Project Settings.

#include "Controller/ProjPlayerController.h"
#include "Controller/PlayerCameraController.h"
#include <EnhancedInputSubsystems.h>
#include <EnhancedInputComponent.h>
#include "GameFramework\Character.h"
#include "GameFramework\CharacterMovementComponent.h"
#include "Interaction/CombatInterface.h"
#include "Character/TPCharacter.h"
#include "Component/TPAttributeComponent.h"

void AProjPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetMappingContext(DefaultMappingContexts);

	PlayerCameraController = Cast<APlayerCameraController>(PlayerCameraManager);
	TPCharacter = Cast<ATPCharacter>(GetCharacter());
	if (TPCharacter != nullptr)
	{
		PlayerCameraController->TPCharacter = TPCharacter;
		PlayerCameraController->PlayerLocation = PlayerLocation = TPCharacter->GetActorLocation();
		PlayerCameraController->BeginPlayLocation = PlayerLocation;
	}
}

void AProjPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PlayerCameraController->PlayerLocation = PlayerLocation = TPCharacter->GetActorLocation();

	if (PlayerCameraController)
	{
		PlayerCameraController->XYCanFollow = CameraXYCanFollow;
		PlayerCameraController->ZCanFollow = CameraZCanFollow;
	}
}

void AProjPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	check(EInputComponent);
	EInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AProjPlayerController::MoveFunc);
	EInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &AProjPlayerController::MoveStopFunc);
	EInputComponent->BindAction(SprintAction, ETriggerEvent::Triggered, this, &AProjPlayerController::SprintFunc);
	EInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &AProjPlayerController::SprintStopFunc);
	EInputComponent->BindAction(UpAction, ETriggerEvent::Triggered, this, &AProjPlayerController::UpFunc);
	EInputComponent->BindAction(UpAction, ETriggerEvent::Completed, this, &AProjPlayerController::UpStopFunc);
	EInputComponent->BindAction(DownAction, ETriggerEvent::Triggered, this, &AProjPlayerController::DownFunc);
	EInputComponent->BindAction(DownAction, ETriggerEvent::Completed, this, &AProjPlayerController::DownStopFunc);
	EInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AProjPlayerController::JumpFunc);
	EInputComponent->BindAction(AttackAction, ETriggerEvent::Started, this, &AProjPlayerController::AttackFunc);
}

void AProjPlayerController::MoveFunc(const FInputActionValue& Value)
{
	if (!PlayerCanMove) return;
	if (PlayerIsDeath) return;
	PlayerNeedMove = true;

	FVector2D MovementVector = Value.Get<FVector2D>();
	FRotator YawRotator = FRotator(0.f, GetControlRotation().Yaw, 0.f);
	FVector ForwardVector = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::X);

	if (APawn* ControllerPawn = GetPawn<APawn>())
	{
		ControllerPawn->AddMovementInput(ForwardVector, MovementVector.X);
	}
}

void AProjPlayerController::MoveStopFunc()
{
	PlayerNeedMove = false;
}

void AProjPlayerController::SprintFunc()
{
	//TPCharacter->GetMovementComponent()->Walk
	if (TPCharacter->AttributeComponent->GetStamina() > 0)
	{
		TPCharacter->IsSprint = true;
	}
	else
	{
		TPCharacter->IsSprint = false;
	}
}

void AProjPlayerController::SprintStopFunc()
{
	TPCharacter->IsSprint = false;
}

void AProjPlayerController::JumpFunc()
{
	if (!PlayerCanMove) return;
	if (PlayerIsDeath) return;
	if (GetCharacter())
	{
		GetCharacter()->Jump();
	}
}

void AProjPlayerController::AttackFunc()
{
	if (PlayerIsDeath) return;
	ICombatInterface* CombatInterface = Cast<ICombatInterface>(TPCharacter);
	if (CombatInterface)
	{
		CombatInterface->Execute_Attack(TPCharacter);
	}
}

void AProjPlayerController::UpFunc()
{
	if (PlayerIsDeath) return;
	TPCharacter->IsUp = true;
}

void AProjPlayerController::UpStopFunc()
{
	if (PlayerIsDeath) return;
	TPCharacter->IsUp = false;
}

void AProjPlayerController::DownFunc()
{
	if (PlayerIsDeath) return;
	TPCharacter->IsDown = true;
}

void AProjPlayerController::DownStopFunc()
{
	if (PlayerIsDeath) return;
	TPCharacter->IsDown = false;
}

void AProjPlayerController::SetMappingContext(TArray<TObjectPtr<UInputMappingContext>> InputMappingContexts)
{
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		int32 Index = 0;
		for (TObjectPtr<UInputMappingContext> MappingContext : InputMappingContexts)
		{
			Subsystem->AddMappingContext(MappingContext, Index);
			Index++;
		}
	}
}
