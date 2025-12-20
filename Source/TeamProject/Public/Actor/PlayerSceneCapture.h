// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerSceneCapture.generated.h"

class USceneCaptureComponent2D;

UCLASS()
class TEAMPROJECT_API APlayerSceneCapture : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneCaptureComponent2D> PlayerSceneCaptureComponent;

	UPROPERTY(BlueprintReadWrite)
	FTransform TargetCameraTransform;

public:

	APlayerSceneCapture();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
