
#include "Actor/TPWeapon.h"
#include "Components/BoxComponent.h"
#include "NiagaraComponent.h"
#include "Interaction/CombatInterface.h"
#include <Kismet/GameplayStatics.h>

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

	BoxTraceStart = CreateDefaultSubobject<USceneComponent>(TEXT("BoxTraceStart"));
	BoxTraceStart->SetupAttachment(WeaponCollision);
	BoxTraceEnd = CreateDefaultSubobject<USceneComponent>(TEXT("BoxTraceEnd"));
	BoxTraceEnd->SetupAttachment(WeaponCollision);

	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

FHitResult ATPWeapon::WeaponBoxTrace()
{
	FHitResult HitResult;

	FVector Start = BoxTraceStart->GetComponentLocation();
	FVector End = BoxTraceEnd->GetComponentLocation();

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GetOwner());
	IgnorActors.Add(GetOwner());

	for (AActor* Actors : IgnorActors)
	{
		ActorsToIgnore.AddUnique(Actors);
	}

	UKismetSystemLibrary::BoxTraceSingle(this, Start, End, BoxTraceExtent, BoxTraceStart->GetComponentRotation(), ETraceTypeQuery::TraceTypeQuery1, false, ActorsToIgnore, bShowBoxDebug ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None, HitResult, true);

	if (HitResult.GetActor())
	{
		if (ICombatInterface* TargetActor = Cast<ICombatInterface>(HitResult.GetActor()))
		{
			//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("Hit Actor: %s"), *HitResult.GetActor()->GetName()));
			TargetActor->Execute_GetHit(HitResult.GetActor(), WeaponDamage, HitResult.ImpactPoint, GetOwner());
		}
		IgnorActors.AddUnique(HitResult.GetActor());
		return HitResult;
	}
	else
	{
		return FHitResult();
	}
}
	
// Called when the game starts or when spawned
void ATPWeapon::BeginPlay()
{
	Super::BeginPlay();
	WeaponCollision->OnComponentBeginOverlap.AddDynamic(this, &ATPWeapon::OnWeaponOverlapBegin);
	WeaponCollision->OnComponentEndOverlap.AddDynamic(this, &ATPWeapon::OnWeaponOverlapEnd);
}

void ATPWeapon::OnWeaponOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void ATPWeapon::OnWeaponOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}


// Called every frame
void ATPWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

