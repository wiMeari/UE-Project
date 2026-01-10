#include "Character/TPCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NiagaraComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Actor/TPWeapon.h"
#include "Component/TPAttributeComponent.h"
#include "Components/CapsuleComponent.h"

ATPCharacter::ATPCharacter()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	DissolvedEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("DissolvedEffect"));
	DissolvedEffect->SetupAttachment(GetMesh());

	//WeaponDissolvedEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("WeaponDissolvedEffect"));
	//WeaponDissolvedEffect->SetupAttachment(WeaponMesh);
}

void ATPCharacter::Attack_Implementation()
{
	Super::Attack_Implementation();
}

void ATPCharacter::GetHit_Implementation(float Damage,const FVector& HitDirection, AActor* Hitter)
{
	Super::GetHit_Implementation(Damage, HitDirection, Hitter);
}

void ATPCharacter::Death_Implementation()
{
	Super::Death_Implementation();
	//UE_LOG(LogTemp, Warning, TEXT("Character Death"));
}

void ATPCharacter::BeginPlay()
{
	Super::BeginPlay();
	WeaponActor = Cast<ATPWeapon>(WeaponComponent->GetChildActor());
	if (WeaponActor)
	{
		WeaponActor->SetOwner(this);
	}
}

void ATPCharacter::PlayerResurrection_Implementation()
{
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);

	GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	GetMesh()->SetSimulatePhysics(false);
}

void ATPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetCharacterMovement())
	{
		if (IsSprint)
		{
			GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
		}
		else
		{
			GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
		}
	}

	DownLineTrance();
}

void ATPCharacter::DownLineTrance()
{

	FVector Start = GetActorLocation();
	FVector End = FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - DownLength);

	TArray<AActor*> ActorToIgnor;

	CanDownAttack = UKismetSystemLibrary::LineTraceSingle(this, Start, End, ETraceTypeQuery::TraceTypeQuery1, false, ActorToIgnor, ShouldDebug ? EDrawDebugTrace::ForOneFrame : EDrawDebugTrace::None, HitRes, true);
	CanLaunchDownAttack = Start.Z - HitRes.Location.Z < DownAttackLength;
}

void ATPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

}
