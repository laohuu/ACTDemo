// Fill out your copyright notice in the Description page of Project Settings.


#include "HCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AHCharacter::AHCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void AHCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

// Called to bind functionality to input
void AHCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AHCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}
