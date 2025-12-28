
#include "Actor/TPWeapon.h"
#include "Components/BoxComponent.h"
#include "NiagaraComponent.h"

// Sets default values
ATPWeapon::ATPWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	RootComponent = WeaponMesh;
	WeaponCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollision"));
	WeaponCollision->SetupAttachment(RootComponent);
	WeaponDissolvedEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("WeaponDissolvedEffect"));
	WeaponDissolvedEffect->SetupAttachment(WeaponMesh);

	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void ATPWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATPWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

