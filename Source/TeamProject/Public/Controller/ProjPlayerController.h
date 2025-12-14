// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ProjPlayerController.generated.h"

class APlayerCameraController;

UCLASS()
class TEAMPROJECT_API AProjPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	TObjectPtr<APlayerCameraController> PlayerCameraController;

	UPROPERTY()
	float  PlayerLocation;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
};
