// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "PlayerCameraController.generated.h"

class ACameraActor;

UCLASS()
class TEAMPROJECT_API APlayerCameraController : public APlayerCameraManager
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACameraActor> CameraActorClass;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ACameraActor> PlayerCameraActor;

	UPROPERTY(BlueprintReadWrite)
	FVector TargetCameraLocation;

	UPROPERTY(BlueprintReadWrite)
	FRotator TargetCameraRotator;

public:

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
};
