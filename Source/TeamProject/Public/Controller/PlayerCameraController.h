// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "PlayerCameraController.generated.h"

class ACameraActor;
class ATPCharacter;
class APlayerSceneCapture;

UCLASS()
class TEAMPROJECT_API APlayerCameraController : public APlayerCameraManager
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACameraActor> CameraActorClass;

	UPROPERTY(BlueprintReadOnly, Category = "CameraActor")
	TObjectPtr<ACameraActor> PlayerCameraActor;

	UPROPERTY(BlueprintReadOnly, Category = "CameraActor")
	TObjectPtr<ACameraActor> AnotherPlayerCameraActor;

	UPROPERTY(BlueprintReadOnly, Category = "PlayerProperty")
	TObjectPtr<ATPCharacter> TPCharacter;

	UPROPERTY(BlueprintReadOnly, Category = "PlayerProperty")
	FVector PlayerLocation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CameraProperty")
	FVector BeginPlayLocation;

	UPROPERTY(BlueprintReadWrite, Category = "CameraProperty")
	FVector TargetLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraProperty")
	FVector TargetLocationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraProperty")
	FRotator TargetRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraProperty")
	float CameraForwardLenght = 1;

	UPROPERTY(BlueprintReadWrite, Category = "CameraProperty")
	bool XYCanFollow = true;

	UPROPERTY(BlueprintReadWrite, Category = "CameraProperty")
	bool ZCanFollow = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraProperty")
	float XYInterpSpeed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraProperty")
	float ZInterpSpeed = 0;

	UPROPERTY(BlueprintReadWrite, Category = "SceneCapture")
	TObjectPtr<APlayerSceneCapture> PlayerSceneCaptureActor;

public:

	virtual void Tick(float DeltaTime) override;


protected:
	virtual void BeginPlay() override;

private:
	void UpdateTargetLocation();


	TObjectPtr<ACameraActor> InitializeActor(TSubclassOf<ACameraActor> TargetClass, const FString &CameraName);
};
