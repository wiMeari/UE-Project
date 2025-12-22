// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NiagaraComponent.h"
#include "Component/TPAttributeComponent.h"d

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintNormal(FVector(1.f, 0.f, 0.f));

	DissolvedEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("DissolvedEffect"));
	DissolvedEffect->SetupAttachment(GetMesh());

	AttributeComponent = CreateDefaultSubobject<UTPAttributeComponent>(TEXT("AttributeComponent"));
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
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

