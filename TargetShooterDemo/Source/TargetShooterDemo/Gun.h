// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class TARGETSHOOTERDEMO_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Returns true if the gun is out of ammo
	UFUNCTION(BlueprintPure)
	bool IsGunEmpty() const;

	// Returns the gun's current ammo count
	UFUNCTION(BlueprintPure)
	float GetCurrentAmmo() const;

	// Returns the gun's maximum ammo count
	UFUNCTION(BlueprintPure)
	float GetMaxAmmo() const;

	// Called when the player reloads or the gun is empty
	UFUNCTION(BlueprintCallable)
	void Reload();

	// Called when the player shoots
	UFUNCTION(BlueprintCallable)
	void PullTrigger();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Root scene component to derive the gun's transform
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	// The gun's skeletal mesh
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	// The gun's maximum range
	UPROPERTY(EditAnywhere)
	float MaxRange = 2000.f;

	// The gun's force of impact
	UPROPERTY(EditAnywhere)
	float ImpactForce = 1000000.f;

	// The gun's muzzle flash effect
	UPROPERTY(EditAnywhere)
	UParticleSystem* MuzzleFlash;

	// The bullet impact effect
	UPROPERTY(EditAnywhere)
	UParticleSystem* ImpactEffect;

	// The gun's current ammo
	UPROPERTY(VisibleAnywhere)
	float CurrentAmmo;

	// The gun's maximum ammo
	UPROPERTY(EditDefaultsOnly)
	float MaxAmmo = 15.f;

	// Returns the controller for the gun's owner pawn
	AController* GetOwnerController() const;

	/*
	 * Checks the result of a line trace from the gun
	 *
	 * @param	Hit  Out paramerter reference to the struct containing information about one hit of the trace
	 * @param	ShotDirection  Out parameter reference to the directional vector of the line trace
	 * @returns true if the line trace reaches its maximum range
	 */
	bool GunTrace(FHitResult& Hit, FVector& ShotDirection);
};
