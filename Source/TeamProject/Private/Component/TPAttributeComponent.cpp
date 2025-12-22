// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/TPAttributeComponent.h"

// Sets default values for this component's properties
UTPAttributeComponent::UTPAttributeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTPAttributeComponent::ReceiveDamage(float DamageAmount)
{
	Health = FMath::Clamp(Health - DamageAmount, 0.0f, MaxHealth);
}

void UTPAttributeComponent::UseMana(float ManaCost)
{
	Mana = FMath::Clamp(Mana - ManaCost, 0.0f, MaxMana);
}

// Called when the game starts
void UTPAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTPAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

