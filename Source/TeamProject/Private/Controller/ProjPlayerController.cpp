// Fill out your copyright notice in the Description page of Project Settings.

#include "Controller/ProjPlayerController.h"
#include "Controller/PlayerCameraController.h"
#include <EnhancedInputSubsystems.h>
#include <EnhancedInputComponent.h>
#include "GameFramework\Character.h"
#include "GameFramework\CharacterMovementComponent.h"
#include "Character/TPCharacter.h"

void AProjPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetMappingContext(DefaultMappingContexts);

	PlayerCameraController = Cast<APlayerCameraController>(PlayerCameraManager);
	TPCharacter = Cast<ATPCharacter>(GetCharacter());
	PlayerCameraController->TPCharacter = TPCharacter;
}

void AProjPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerCameraController)
	{
		PlayerCameraController->CanFollow = CameraCanFollow;
	}
}

void AProjPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	check(EInputComponent);
	EInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AProjPlayerController::MoveFunc);
	EInputComponent->BindAction(SprintAction, ETriggerEvent::Triggered, this, &AProjPlayerController::SprintFunc);
	EInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &AProjPlayerController::SprintStopFunc);
	EInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AProjPlayerController::JumpFunc);
}

void AProjPlayerController::MoveFunc(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	FRotator YawRotator = FRotator(0.f, GetControlRotation().Yaw, 0.f);
	FVector ForwardVector = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::X);

	if (APawn* ControllerPawn = GetPawn<APawn>())
	{
		ControllerPawn->AddMovementInput(-ForwardVector, MovementVector.X);
	}
}

void AProjPlayerController::SprintFunc()
{
	//TPCharacter->GetMovementComponent()->Walk
	TPCharacter->IsSprint = true;
}

void AProjPlayerController::SprintStopFunc()
{
	TPCharacter->IsSprint = false;
}

void AProjPlayerController::JumpFunc()
{
	if (GetCharacter())
	{
		GetCharacter()->Jump();
	}
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
