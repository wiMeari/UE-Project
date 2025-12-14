// Fill out your copyright notice in the Description page of Project Settings.

#include "Controller/ProjPlayerController.h"
#include "Controller/PlayerCameraController.h"
#include <EnhancedInputSubsystems.h>
#include <EnhancedInputComponent.h>
#include "GameFramework\Character.h"

void AProjPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetMappingContext(DefaultMappingContexts);

	PlayerCameraController = Cast<APlayerCameraController>(PlayerCameraManager);
}

void AProjPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PlayerLocation = GetCharacter()->GetActorLocation();

	TargetLocation = PlayerLocation + TargetLocationOffset;

	if (PlayerCameraController)
	{
		PlayerCameraController->TargetCameraLocation = TargetLocation;
	}
}

void AProjPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	check(EInputComponent);
	EInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AProjPlayerController::MoveFunc);
	EInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AProjPlayerController::JumpFunc);
}

void AProjPlayerController::MoveFunc(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	FRotator YawRotator = FRotator(0.f, GetControlRotation().Yaw, 0.f);
	FVector ForwardVector = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::Y);

	if (APawn* ControllerPawn = GetPawn<APawn>())
	{
		ControllerPawn->AddMovementInput(ForwardVector, MovementVector.X);
	}
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
