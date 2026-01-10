#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "TPEnemy.generated.h"

class UPawnSensingComponent;
class AAIController;
class USphereComponent;
class ATPCharacter;

UCLASS()
class TEAMPROJECT_API ATPEnemy : public ACharacterBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USphereComponent> SearchCharacterSphere;

	UPROPERTY(BlueprintReadWrite, Category = "Combat")
	bool IsChase = false;

	UPROPERTY(BlueprintReadWrite)
	bool CanMove = true;

	UPROPERTY(BlueprintReadWrite)
	bool IsDeath = false;

	ATPEnemy();

	virtual void Tick(float DeltaTime) override;

	void ChaseState();

	void PatrolState();

	bool IntargetRadius(float Radius);

	void MoveToTarget();

	void ChoosePatrolTarget();

	virtual void Attack_Implementation() override;

	virtual void GetHit_Implementation(float Damage,const FVector& HitDirection, AActor* Hitter) override;

	virtual void Death_Implementation() override;
protected:

	UPROPERTY(EditAnywhere, Category = "Combat | Patrol")
	float MaxPatrolRadius = 1000;

	UPROPERTY(BlueprintReadOnly, Category = "Combat | Patrol")
	FVector LeftPatrolTarget;

	UPROPERTY(BlueprintReadOnly, Category = "Combat | Patrol")
	FVector RightPatrolTarget;

	UPROPERTY(BlueprintReadOnly, Category = "Combat | Patrol")
	FVector CurrentPatrolTarget;

	UPROPERTY(EditAnywhere, Category = "Combat | Patrol")
	float PatrolRadiusOffset = 50;

	UPROPERTY(BlueprintReadWrite, Category = "Combat | Chase")
	TObjectPtr<ATPCharacter> ChaseTarget;

	UPROPERTY(BlueprintReadOnly, Category = "Combat | Chase")
	FVector ChaseTargetLocation;

	UPROPERTY(EditAnywhere, Category = "Combat | Chase")
	float AttackRadius = 0;

	UPROPERTY(EditAnywhere, Category = "Combat | Chase")
	float OutOfcombatRadius = 500;

	UPROPERTY()
	AAIController* EnemyController;

	UFUNCTION()
	void SeachSphereBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void BeginPlay() override;

	void CalcPatrolTarget();
};
