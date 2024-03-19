// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetShooterCharacter.h"

//////////////////////////////////////////////////////////////////////////
// ATargetShooterCharacter
//////////////////////////////////////////////////////////////////////////

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

	// Bind movement input
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATargetShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ATargetShooterCharacter::MoveRight);

	// Bind look input
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUpRateMouse"), this, &ATargetShooterCharacter::LookUpRateMouse);
	PlayerInputComponent->BindAxis(TEXT("LookRightRateMouse"), this, &ATargetShooterCharacter::LookRightRateMouse);
	PlayerInputComponent->BindAxis(TEXT("LookUpRateGamepad"), this, &ATargetShooterCharacter::LookUpRateGamepad);
	PlayerInputComponent->BindAxis(TEXT("LookRightRateGamepad"), this, &ATargetShooterCharacter::LookRightRateGamepad);

	// Bind jump input
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);

	// Bind shoot input
	//PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &ATargetShooterCharacter::Shoot);

	// Bind reload input
	//PlayerInputComponent->BindAction(TEXT("Reload"), EInputEvent::IE_Pressed, this, &ATargetShooterCharacter::Reload);
}

void ATargetShooterCharacter::MoveForward(float AxisValue)
{
	if (AxisValue != 0.f)
	{
		// Move forward/backward at the given AxisValue
		AddMovementInput(GetActorForwardVector() * AxisValue);
	}
}

void ATargetShooterCharacter::MoveRight(float AxisValue)
{
	if (AxisValue != 0.f)
	{
		// Strafe right/left at the given AxisValue
		AddMovementInput(GetActorRightVector() * AxisValue);
	}
}

void ATargetShooterCharacter::LookUpRateMouse(float RateValue)
{
	if (RateValue != 0.f)
	{
		// Look up/down at the given RateValue
		AddControllerPitchInput(RateValue * RotationRateMouse * GetWorld()->GetDeltaSeconds());
	}
}

void ATargetShooterCharacter::LookRightRateMouse(float RateValue)
{
	if (RateValue != 0.f)
	{
		// Look right/left at the given RateValue
		AddControllerYawInput(RateValue * RotationRateMouse * GetWorld()->GetDeltaSeconds());
	}
}

void ATargetShooterCharacter::LookUpRateGamepad(float RateValue)
{
	if (RateValue != 0.f)
	{
		// Look up/down at the given RateValue
		AddControllerPitchInput(RateValue * RotationRateGamepad * GetWorld()->GetDeltaSeconds());
	}
}

void ATargetShooterCharacter::LookRightRateGamepad(float RateValue)
{
	if (RateValue != 0.f)
	{
		// Look up/down at the given RateValue
		AddControllerYawInput(RateValue * RotationRateGamepad * GetWorld()->GetDeltaSeconds());
	}
}