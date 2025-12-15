// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ProjPlayerController.generated.h"

class APlayerCameraController;
class ATPCharacter;
class UInputMappingContext;
class UInputAction;
class UCharacterMovementComponent;
struct FInputActionValue;

UCLASS()
class TEAMPROJECT_API AProjPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TArray<TObjectPtr<UInputMappingContext>> DefaultMappingContexts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> SprintAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY()
	TObjectPtr<APlayerCameraController> PlayerCameraController;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ATPCharacter> TPCharacter;

	UPROPERTY()
	TObjectPtr<UCharacterMovementComponent> MovementComponent;

	UPROPERTY(BlueprintReadWrite, Category = "Camera")
	bool CameraCanFollow = true;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
private:

	void MoveFunc(const FInputActionValue& Value);

	void SprintFunc();

	void SprintStopFunc();

	void JumpFunc();

	void SetMappingContext(TArray<TObjectPtr<UInputMappingContext>> InputMappingContexts);
};
