// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TPAttributeComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEAMPROJECT_API UTPAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTPAttributeComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable,BlueprintPure)
	FORCEINLINE float GetHealth() const { return Health; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetStamina() const { return Stamina; }

	UFUNCTION(BlueprintCallable,BlueprintPure)
	FORCEINLINE float GetMaxHealth() const { return MaxHealth; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE float GetMaxStamina() const { return MaxStamina; }

	UFUNCTION(BlueprintCallable)
	void ReceiveDamage(float DamageAmount);

	UFUNCTION(BlueprintCallable)
	void UseStamina(float ManaCost);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Attribute")
	float Health;

	UPROPERTY(EditAnywhere, Category = "Attribute")
	float MaxHealth;

	UPROPERTY(EditAnywhere, Category = "Attribute")
	float Stamina;

	UPROPERTY(EditAnywhere, Category = "Attribute")
	float MaxStamina;
		
};
