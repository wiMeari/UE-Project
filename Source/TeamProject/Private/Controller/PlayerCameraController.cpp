// Fill out your copyright notice in the Description page of Project Settings.

#include "Controller/PlayerCameraController.h"
#include "Camera/CameraActor.h"

void APlayerCameraController::Tick(float DeltaTime)
{
}

void APlayerCameraController::BeginPlay()
{
	CameraActor = GetWorld()->SpawnActor<ACameraActor>(CameraActorClass);
	CameraActor->SetActorLocation(FVector(0.f, 0.f, 0.f));
	SetViewTarget(CameraActor);
}
