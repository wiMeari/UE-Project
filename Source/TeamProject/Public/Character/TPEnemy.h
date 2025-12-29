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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UPawnSensingComponent> PawnSensingComp;

	ATPEnemy();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
};
