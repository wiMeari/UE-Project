// Fill out your copyright notice in the Description page of Project Settings.

#include "Controller/PlayerCameraController.h"
#include "Camera/CameraActor.h"

void APlayerCameraController::BeginPlay()
{
	Super::BeginPlay();

	PlayerCameraActor = GetWorld()->SpawnActor<ACameraActor>(CameraActorClass);
	PlayerCameraActor->SetActorLocation(TargetCameraLocation);
	SetViewTarget(PlayerCameraActor);
}

void APlayerCameraController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerCameraActor == nullptr && GetWorld())
	{
		PlayerCameraActor = GetWorld()->SpawnActor<ACameraActor>(CameraActorClass);
	}

	PlayerCameraActor->SetActorLocation(TargetCameraLocation);
}

