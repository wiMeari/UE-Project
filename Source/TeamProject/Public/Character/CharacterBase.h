// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interaction/CombatInterface.h"
#include "CharacterBase.generated.h"

class UNiagaraComponent;
class UTPAttributeComponent;
class ATPWeapon;

UCLASS()
class TEAMPROJECT_API ACharacterBase : public ACharacter, public ICombatInterface
{
	GENERATED_BODY()

public:

	//UPROPERTY(EditAnywhere,BlueprintReadWrite)
	//TObjectPtr<UStaticMeshComponent> WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UTPAttributeComponent> AttributeComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UChildActorComponent> WeaponComponent;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ATPWeapon> WeaponClass;

	//UPROPERTY(BlueprintReadOnly)
	//TObjectPtr<ATPWeapon> WeaponActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float SprintSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float RunSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsSprint;

public:
	// Sets default values for this character's properties
	ACharacterBase();

	virtual void Attack_Implementation() override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
