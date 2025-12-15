// Fill out your copyright notice in the Description page of Project Settings.

#include "Controller/PlayerCameraController.h"
#include "Camera/CameraActor.h"
#include <Controller/ProjPlayerController.h>
#include <Character/TPCharacter.h>
#include "Kismet/KismetSystemLibrary.h"
#include <Kismet/KismetMathLibrary.h>

void APlayerCameraController::BeginPlay()
{
	Super::BeginPlay();

	PlayerCameraActor = GetWorld()->SpawnActor<ACameraActor>(CameraActorClass);
	PlayerCameraActor->SetActorLocation(FVector(-600, 1000, 300));
	SetViewTarget(PlayerCameraActor);
}

void APlayerCameraController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerCameraActor == nullptr && GetWorld())
	{
		PlayerCameraActor = GetWorld()->SpawnActor<ACameraActor>(CameraActorClass);
	}

	bool retFlag;
	UpdateTargetLocation(retFlag);
	if (retFlag) return;

	if (CanFollow)
	{
		FVector CameraLocation = PlayerCameraActor->GetActorLocation();

		FVector InterpLocation = UKismetMathLibrary::VInterpTo(FVector(CameraLocation.X, CameraLocation.Y, 0), FVector(TargetLocation.X, TargetLocation.Y, 0), DeltaTime, XYInterpSpeed);
		InterpLocation.Z = UKismetMathLibrary::FInterpTo(CameraLocation.Z, TargetLocation.Z, DeltaTime, ZInterpSpeed);
		
		PlayerCameraActor->SetActorLocation(InterpLocation);
	}
}

void APlayerCameraController::UpdateTargetLocation(bool& retFlag)
{
	retFlag = true;
	if (TPCharacter == nullptr) return;

	PlayerLocation = TPCharacter->GetActorLocation();

	TargetLocation = PlayerLocation + TargetLocationOffset;

	float PlayerForward = TPCharacter->GetActorForwardVector().Y < 0 ? -1 : 1;

	TargetLocation.Y += CameraForwardLenght * PlayerForward;

	//PlayerCameraActor->SetActorLocation(TargetCameraLocation);
	retFlag = false;
}

