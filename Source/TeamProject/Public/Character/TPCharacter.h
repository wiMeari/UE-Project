#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "TPCharacter.generated.h"

class UNiagaraComponent;

UCLASS()
class TEAMPROJECT_API ATPCharacter : public ACharacterBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UNiagaraComponent> DissolvedEffect;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TObjectPtr<UNiagaraComponent> WeaponDissolvedEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsUp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsDown;

	UPROPERTY(BlueprintReadOnly, Category = "DownTarce")
	FHitResult HitRes;

	UPROPERTY(BlueprintReadWrite, Category = "DownTarce")
	bool CanDownAttack;

	UPROPERTY(BlueprintReadWrite, Category = "DownTarce")
	bool CanLaunchDownAttack;

	UPROPERTY(EditAnywhere, Category = "DownTarce")
	float DownAttackLength;

	UPROPERTY(EditAnywhere, Category = "DownTarce")
	float DownLength = 0;

	UPROPERTY(EditAnywhere, Category = "DownTarce")
	bool ShouldDebug;
public:
	ATPCharacter();

	virtual void Attack_Implementation() override;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	void DownLineTrance();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
