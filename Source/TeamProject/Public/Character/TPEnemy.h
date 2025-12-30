#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "TPEnemy.generated.h"

class UPawnSensingComponent;

UCLASS()
class TEAMPROJECT_API ATPEnemy : public ACharacterBase
{
	GENERATED_BODY()
	
public:

	ATPEnemy();

	virtual void Tick(float DeltaTime) override;

	virtual void Attack_Implementation() override;

	virtual void GetHit_Implementation(float Damage,const FVector& HitDirection, AActor* Hitter) override;

	virtual void Death_Implementation() override;
protected:
	virtual void BeginPlay() override;
};
