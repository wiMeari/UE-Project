#include "Library/TPFunctionLibrary.h"
#include "Animation/AnimMontage.h"
#include "Kismet/KismetMathLibrary.h"

void UTPFunctionLibrary::SwapPlaces(FVector FirstVector, FVector SecondVector, FVector& OutFirstVector, FVector& OutSecondVector)
{
	FVector TempVector = FirstVector;
	OutFirstVector = SecondVector;
	OutSecondVector = TempVector;
}

UAnimMontage* UTPFunctionLibrary::SelectMontageFromMontageArray(TArray<UAnimMontage*> MontageArray, bool& IsNotNull)
{
	if (MontageArray.Num() > 0)
	{
		IsNotNull = true;
		return MontageArray[UKismetMathLibrary::RandomInteger(MontageArray.Num())];
	}
	else
	{
		IsNotNull = false;
		return nullptr;
	}
	return nullptr;
}

