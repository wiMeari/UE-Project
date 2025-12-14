// Fill out your copyright notice in the Description page of Project Settings.

#include "Controller/PlayerCameraController.h"
#include "Camera/CameraActor.h"

void APlayerCameraController::BeginPlay()
{
	CameraActor = GetWorld()->SpawnActor<ACameraActor>(CameraActorClass);
	CameraActor->SetActorLocation(TargetCameraLocation);
	SetViewTarget(CameraActor);
}

void APlayerCameraController::Tick(float DeltaTime)
{
	CameraActor->SetActorLocation(TargetCameraLocation);
}

