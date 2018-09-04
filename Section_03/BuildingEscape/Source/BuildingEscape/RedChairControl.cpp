// Fill out your copyright notice in the Description page of Project Settings.

#include "YellowChairControl.h"
#include "RedChairControl.h"


// Sets default values for this component's properties
URedChairControl::URedChairControl()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URedChairControl::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	
}


// Called every frame
void URedChairControl::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (RedPlate->IsOverlappingActor(Owner)) {

		RedReceiver.Broadcast();
	}
}

