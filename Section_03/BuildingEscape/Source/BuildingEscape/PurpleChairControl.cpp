// Fill out your copyright notice in the Description page of Project Settings.

#include "PurpleChairControl.h"


// Sets default values for this component's properties
UPurpleChairControl::UPurpleChairControl()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPurpleChairControl::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();

}


// Called every frame
void UPurpleChairControl::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PurplePlate->IsOverlappingActor(Owner)) {

		PurpleReceiver.Broadcast();

	}
}

