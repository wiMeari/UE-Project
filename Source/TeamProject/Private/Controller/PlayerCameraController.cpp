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

	PlayerCameraActor = InitializeCameraInSense(CameraActorClass, FString("PlayerCameraActor"));
	AnotherPlayerCameraActor = InitializeCameraInSense(CameraActorClass, FString("AnotherCameraActor"));

	if (PlayerCameraActor != nullptr)
	{
		PlayerCameraActor->SetActorLocation(BeginPlayLocation);
		SetViewTarget(PlayerCameraActor);
	}
}

void APlayerCameraController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerCameraActor == nullptr && GetWorld())
	{
		PlayerCameraActor = GetWorld()->SpawnActor<ACameraActor>(CameraActorClass);
	}

	UpdateTargetLocation();

	if (CanFollow)
	{
		FVector CameraLocation = PlayerCameraActor->GetActorLocation();

		FVector InterpLocation = UKismetMathLibrary::VInterpTo(FVector(CameraLocation.X, CameraLocation.Y, 0), FVector(TargetLocation.X, TargetLocation.Y, 0), DeltaTime, XYInterpSpeed);
		InterpLocation.Z = UKismetMathLibrary::FInterpTo(CameraLocation.Z, TargetLocation.Z, DeltaTime, ZInterpSpeed);
		
		PlayerCameraActor->SetActorLocation(InterpLocation);
	}
}

void APlayerCameraController::UpdateTargetLocation()
{

	if (TPCharacter == nullptr) return;

	TargetLocation = PlayerLocation + TargetLocationOffset;

	float PlayerForward = TPCharacter->GetActorForwardVector().Y < 0 ? -1 : 1;

	TargetLocation.Y += CameraForwardLenght * PlayerForward;

}

TObjectPtr<ACameraActor> APlayerCameraController::InitializeCameraInSense(TSubclassOf<ACameraActor> TargetClass, const FString& CameraName)
{
	TObjectPtr<ACameraActor> InitialTarget = GetWorld()->SpawnActor<ACameraActor>(TargetClass);
	if (InitialTarget != nullptr)
	{
		InitialTarget->SetActorLabel(CameraName);
		return InitialTarget;
	}
	return nullptr;
}

