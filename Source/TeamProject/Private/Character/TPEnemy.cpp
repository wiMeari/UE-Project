#include "Character/TPEnemy.h"
#include "Perception/PawnSensingComponent.h"
#include "Actor/TPWeapon.h"

ATPEnemy::ATPEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	
}

void ATPEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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

void ATPEnemy::BeginPlay()
{
	Super::BeginPlay();

	WeaponActor = Cast<ATPWeapon>(WeaponComponent->GetChildActor());
	if (WeaponActor)
	{
		WeaponActor->SetOwner(this);
	}
}
