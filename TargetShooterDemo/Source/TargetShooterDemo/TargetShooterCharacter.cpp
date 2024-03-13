// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetShooterCharacter.h"

// Sets default values
ATargetShooterCharacter::ATargetShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATargetShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATargetShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATargetShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

