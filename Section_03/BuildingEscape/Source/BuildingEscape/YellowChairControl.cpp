// Fill out your copyright notice in the Description page of Project Settings.

#include "YellowChairControl.h"


// Sets default values for this component's properties
UYellowChairControl::UYellowChairControl()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UYellowChairControl::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	
}


// Called every frame
void UYellowChairControl::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (YellowPlate->IsOverlappingActor(Owner)) {

		YellowReceiver.Broadcast();


	}
}

