// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/TPCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

ATPCharacter::ATPCharacter()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
}

void ATPCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ATPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetCharacterMovement())
	{
		if (IsSprint)
		{
			GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
		}
		else
		{
			GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
		}
	}
}

void ATPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

}
