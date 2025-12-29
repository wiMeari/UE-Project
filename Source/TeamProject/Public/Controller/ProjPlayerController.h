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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|MappingContext")
	TArray<TObjectPtr<UInputMappingContext>> DefaultMappingContexts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Move")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Move")
	TObjectPtr<UInputAction> SprintAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Move")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Skill And Attack")
	TObjectPtr<UInputAction> SwitchSenseAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Skill And Attack")
	TObjectPtr<UInputAction> AttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Direction")
	TObjectPtr<UInputAction> UpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Direction")
	TObjectPtr<UInputAction> DownAction;

	UPROPERTY(BlueprintReadWrite, Category = "Move")
	bool PlayerCanMove = true;

	UPROPERTY(BlueprintReadWrite, Category = "Move")
	bool PlayerNeedMove;

public:
	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(BlueprintReadOnly, Category = "Camera")
	TObjectPtr<APlayerCameraController> PlayerCameraController;

	UPROPERTY(BlueprintReadOnly, Category = "PlayerProperty")
	TObjectPtr<ATPCharacter> TPCharacter;

	UPROPERTY(BlueprintReadOnly, Category = "PlayerProperty")
	FVector PlayerLocation;

	UPROPERTY(BlueprintReadWrite, Category = "Camera")
	bool CameraCanFollow = true;

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	UFUNCTION(BlueprintNativeEvent)
	void UpFunc();

	UFUNCTION(BlueprintNativeEvent)
	void UpStopFunc();

	UFUNCTION(BlueprintNativeEvent)
	void DownFunc();

	UFUNCTION(BlueprintNativeEvent)
	void DownStopFunc();
private:

	void MoveFunc(const FInputActionValue& Value);

	void MoveStopFunc();

	void SprintFunc();

	void SprintStopFunc();

	void JumpFunc();

	void AttackFunc();

	void SetMappingContext(TArray<TObjectPtr<UInputMappingContext>> InputMappingContexts);
};
