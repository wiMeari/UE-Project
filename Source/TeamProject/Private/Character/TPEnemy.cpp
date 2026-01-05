#include "Character/TPEnemy.h"
#include "Perception/PawnSensingComponent.h"
#include "Navigation/PathFollowingComponent.h"
#include "Actor/TPWeapon.h"
#include "AIController.h"
#include "Components/SphereComponent.h"
#include "Character/TPCharacter.h"

ATPEnemy::ATPEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SearchCharacterSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SearchCharacterSphere"));
	SearchCharacterSphere->SetupAttachment(RootComponent);

}

void ATPEnemy::BeginPlay()
{
	Super::BeginPlay();

	SearchCharacterSphere->OnComponentBeginOverlap.AddDynamic(this, &ATPEnemy::SeachSphereBeginOverlap);

	CalcPatrolTarget();

	CurrentPatrolTarget = LeftPatrolTarget;

	EnemyController = Cast<AAIController>(GetController());

	WeaponActor = Cast<ATPWeapon>(WeaponComponent->GetChildActor());
	if (WeaponActor)
	{
		WeaponActor->SetOwner(this);
	}
}

void ATPEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (IsChase)
	{
		ChaseState();
	}
	else
	{
		PatrolState();
	}
}

void ATPEnemy::ChaseState()
{
	ChaseTargetLocation = ChaseTarget->GetActorLocation();
	CurrentPatrolTarget = ChaseTargetLocation;
	if (EnemyController != nullptr)
	{
		MoveToTarget();
		if ((GetActorLocation() - ChaseTargetLocation).Length() > OutOfcombatRadius)
		{
			IsChase = false;
			ChaseTarget = nullptr;
		}
	}
	if (IntargetRadius(AttackRadius))
	{
		Execute_Attack(this);
	}
}

void ATPEnemy::PatrolState()
{
	if (IntargetRadius(PatrolRadiusOffset))
	{
		ChoosePatrolTarget();
	}
	else
	{
		if (EnemyController != nullptr)
		{
			MoveToTarget();
		}
	}
}

bool ATPEnemy::IntargetRadius(float Radius)
{
	return (GetActorLocation() - CurrentPatrolTarget).Length() <= Radius;
}

void ATPEnemy::ChoosePatrolTarget()
{
	if (CurrentPatrolTarget == LeftPatrolTarget)
	{
		CurrentPatrolTarget = RightPatrolTarget;
	}
	else if (CurrentPatrolTarget == RightPatrolTarget)
	{
		CurrentPatrolTarget = LeftPatrolTarget;
	}
	else if (CurrentPatrolTarget == ChaseTargetLocation)
	{
		CurrentPatrolTarget = (GetActorLocation() - LeftPatrolTarget).Size() < (GetActorLocation() - RightPatrolTarget).Size() ? LeftPatrolTarget : RightPatrolTarget;
	}
	if (EnemyController != nullptr)
	{
		MoveToTarget();
	}
}

void ATPEnemy::Attack_Implementation()
{
	Super::Attack_Implementation();
}

void ATPEnemy::GetHit_Implementation(float Damage,const FVector& HitDirection, AActor* Hitter)
{
	Super::GetHit_Implementation(Damage, HitDirection, Hitter);
}

void ATPEnemy::Death_Implementation()
{
	Super::Death_Implementation();
}

void ATPEnemy::SeachSphereBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ChaseTarget == nullptr)
	{
		if (ChaseTarget = Cast<ATPCharacter>(OtherActor))
		{
			IsChase = true;
		}
	}
}

void ATPEnemy::CalcPatrolTarget()
{
	RightPatrolTarget = GetActorLocation() + FVector(0.f, MaxPatrolRadius, 0.f);
	LeftPatrolTarget = GetActorLocation() - FVector(0.f, MaxPatrolRadius, 0.f);
}

void ATPEnemy::MoveToTarget()
{
	FAIMoveRequest MoveRequest;
	MoveRequest.SetGoalLocation(CurrentPatrolTarget);
	MoveRequest.SetAcceptanceRadius(5.f);
	EnemyController->MoveTo(MoveRequest);
}
