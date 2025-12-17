// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TPFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class TEAMPROJECT_API UTPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "TPFunctionLibrary")
	static void SwapPlaces(FVector FirstVector, FVector SecondVector, FVector& OutFirstVector, FVector& OutSecondVector);

};

