// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/TPCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NiagaraComponent.h"
#include "Kismet/KismetSystemLibrary.h"

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

	WeaponDissolvedEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("WeaponDissolvedEffect"));
	WeaponDissolvedEffect->SetupAttachment(Weapon);
}

void ATPCharacter::Attack_Implementation()
{
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("ATPCharacter Attack"));
}

void ATPCharacter::BeginPlay()
{
	Super::BeginPlay();
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
