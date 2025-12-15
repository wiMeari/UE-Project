// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "PlayerCameraController.generated.h"

class ACameraActor;
class ATPCharacter;

UCLASS()
class TEAMPROJECT_API APlayerCameraController : public APlayerCameraManager
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACameraActor> CameraActorClass;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ACameraActor> PlayerCameraActor;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ATPCharacter> TPCharacter;

	UPROPERTY(BlueprintReadWrite)
	FVector TargetLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector TargetLocationOffset;

	UPROPERTY(BlueprintReadOnly)
	FVector PlayerLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator TargetRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CameraForwardLenght = 1;

	UPROPERTY(BlueprintReadWrite)
	bool CanFollow = true;

	UPROPERTY(EditAnywhere)
	float XYInterpSpeed = 0;

	UPROPERTY(EditAnywhere)
	float ZInterpSpeed = 0;
public:

	virtual void Tick(float DeltaTime) override;


protected:
	virtual void BeginPlay() override;

private:
	void UpdateTargetLocation(bool& retFlag);
};
