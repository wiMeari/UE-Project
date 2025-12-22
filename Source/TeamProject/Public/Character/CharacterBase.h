// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class UNiagaraComponent;
class UTPAttributeComponent;

UCLASS()
class TEAMPROJECT_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere	,BlueprintReadWrite)
	TObjectPtr<UTPAttributeComponent> AttributeComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UNiagaraComponent> DissolvedEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float SprintSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float RunSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsSprint;

public:
	// Sets default values for this character's properties
	ACharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
