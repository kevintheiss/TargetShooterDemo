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
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Root scene component to derive the gun's transform
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	// Gun's skeletal mesh
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;


};
