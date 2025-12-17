// Fill out your copyright notice in the Description page of Project Settings.


#include "Library/TPFunctionLibrary.h"

void UTPFunctionLibrary::SwapPlaces(FVector FirstVector, FVector SecondVector, FVector& OutFirstVector, FVector& OutSecondVector)
{
	FVector TempVector = FirstVector;
	OutFirstVector = SecondVector;
	OutSecondVector = TempVector;
}
