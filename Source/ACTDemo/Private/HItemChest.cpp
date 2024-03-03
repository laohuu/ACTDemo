// Fill out your copyright notice in the Description page of Project Settings.


#include "HItemChest.h"


// Sets default values
AHItemChest::AHItemChest()
{
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = BaseMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
	LidMesh->SetupAttachment(BaseMesh);

	TargetPitch = 110;
}

void AHItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
	bLidOpened = !bLidOpened;
	float CurrPitch = bLidOpened ? TargetPitch : 0.0f;
	LidMesh->SetRelativeRotation(FRotator(CurrPitch, 0, 0));
}

// Called when the game starts or when spawned
void AHItemChest::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
