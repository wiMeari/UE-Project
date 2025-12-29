#include "Character/TPEnemy.h"
#include "Perception/PawnSensingComponent.h"

ATPEnemy::ATPEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
}

void ATPEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATPEnemy::BeginPlay()
{
	Super::BeginPlay();
}
