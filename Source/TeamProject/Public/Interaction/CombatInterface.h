#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CombatInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UCombatInterface : public UInterface
{
	GENERATED_BODY()
};


class TEAMPROJECT_API ICombatInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Combat")
	void Attack();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Combat")
	void GetHit(float Damage,const FVector& HitDirection, AActor* Hitter);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Combat")
	void Death();
};
