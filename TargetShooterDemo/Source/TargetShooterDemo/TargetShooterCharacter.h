// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TargetShooterCharacter.generated.h"

// Forward declare AGun class
class AGun;

UCLASS()
class TARGETSHOOTERDEMO_API ATargetShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATargetShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// Rate of player look rotation on mouse
	UPROPERTY(EditAnywhere)
	float RotationRateMouse = 100.f;

	// Rate of player look rotation on gamepad
	UPROPERTY(EditAnywhere)
	float RotationRateGamepad = 100.f;

	// Gun class to spawn an AGun actor instance into the world
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;

	// Gun pointer to attach to the character's weapon socket in its skeletal mesh
	UPROPERTY()
	AGun* Gun;

	/*
	 * Handles moving forward/backward 
	 */
	void MoveForward(float AxisValue);

	/*
	 * Handles right/left strafing movement
	 */
	void MoveRight(float AxisValue);

	/*
	 * Called via mouse movement input to look up/down at the given rate
	 * 
	 * @param	RateValue	The normalized rotation rate (1.0 on the axis means 100 percent of the desired rotation rate)
	 */
	void LookUpRateMouse(float RateValue);
	
	/*
	 * Called via mouse movement input to look right/left at the given rate
	 * 
	 * @param	RateValue	The normalized rotation rate (1.0 on the axis means 100 percent of the desired rotation rate)
	 */
	void LookRightRateMouse(float RateValue);

	/*
	 * Called via gamepad right thumbstick movement to look up/down at the given rate
	 * 
	 * @param	RateValue	The normalized rotation rate (1.0 on the axis means 100 percent of the desired rotation rate)
	 */
	void LookUpRateGamepad(float RateValue);

	/*
	 * Called via gamepad right thumbstick movement to look right/left at the given rate
	 * 
	 * @param	RateValue	The normalized rotation rate (1.0 on the axis means 100 percent of the desired rotation rate)
	 */
	void LookRightRateGamepad(float RateValue);
};
