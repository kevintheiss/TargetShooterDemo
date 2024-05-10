// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetShooterPlayerController.h"
#include "Blueprint/UserWidget.h"

// Called when the game starts or when spawned
void ATargetShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* HUD = CreateWidget(this, HUDClass);

	if (HUD != nullptr)
	{
		HUD->AddToViewport();
	}
}