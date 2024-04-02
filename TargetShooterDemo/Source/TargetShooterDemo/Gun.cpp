// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set Root
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	// Set Mesh and attach it to Root
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AController* AGun::GetOwnerController() const
{
	// Gun's owner pawn
	APawn* OwnerPawn = Cast<APawn>(GetOwner());

	// Check if OwnerPawn is nullptr
	if (OwnerPawn == nullptr)
	{
		return nullptr;
	}

	// Return OwnerPawn's controller
	return OwnerPawn->GetController();
}

bool AGun::GunTrace(FHitResult& Hit, FVector& ShotDirection)
{
	// Store the return pointer of GetOwnerController
	AController* OwnerController = GetOwnerController();

	// Return false if OwnerController is nullptr
	if (OwnerController == nullptr)
	{
		return false;
	}

	// Location and rotation of the line trace's origin point
	FVector Location;
	FRotator Rotation;

	// Set Location and Rotation out parameters to those of the player's viewpoint
	OwnerController->GetPlayerViewPoint(Location, Rotation);

	// Set ShotDirection to the rotation vector pointing away from the player's viewpoint
	ShotDirection = -Rotation.Vector();

	// The end point of the line trace, which stops at MaxRange
	FVector End = Location + Rotation.Vector() * MaxRange;

	// Struct that defines parameters passed into the line trace collision
	FCollisionQueryParams Params;

	// Ignore the gun and the owning actor in the line trace
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());

	DrawDebugLine(GetWorld(), Location, End, FColor::Red, true, 5.f, 0.5f);

	// Return true if the line trace reaches MaxRange
	return GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_Camera, Params);
}

void AGun::PullTrigger()
{
	// Values to be set by GunTrace out parameters
	FHitResult Hit;
	FVector ShotDirection;

	GunTrace(Hit, ShotDirection);
}

