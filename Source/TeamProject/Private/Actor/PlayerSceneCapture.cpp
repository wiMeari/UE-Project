// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/PlayerSceneCapture.h"
#include "Components/SceneCaptureComponent2D.h"

// Sets default values
APlayerSceneCapture::APlayerSceneCapture()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PlayerSceneCaptureComponent = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("PlayerSceneCaptureComponent"));
}

// Called when the game starts or when spawned
void APlayerSceneCapture::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerSceneCapture::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorTransform(TargetCameraTransform);

}

