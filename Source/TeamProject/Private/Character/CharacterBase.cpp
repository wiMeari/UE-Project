// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Component/TPAttributeComponent.h"
#include "Actor/TPWeapon.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintNormal(FVector(1.f, 0.f, 0.f));

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);

	AttributeComponent = CreateDefaultSubobject<UTPAttributeComponent>(TEXT("AttributeComponent"));

	//WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	//WeaponMesh->SetupAttachment(GetMesh(), TEXT("WeaponSocket"));

	WeaponComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("Weapon"));
	WeaponComponent->SetupAttachment(GetMesh(), TEXT("WeaponSocket"));
}

void ACharacterBase::Attack_Implementation()
{
}
 
void ACharacterBase::GetHit_Implementation(float Damage,const FVector& HitDirection, AActor* Hitter)
{
	if (AttributeComponent)
	{
		AttributeComponent->ReceiveDamage(Damage);
		if (AttributeComponent->GetHealth() == 0)
		{
			Execute_Death(this);
		}
	}
}

void ACharacterBase::Death_Implementation()
{
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

	GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetMesh()->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	/*WeaponComponent->SetChildActorClass(WeaponClass);*/

}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

