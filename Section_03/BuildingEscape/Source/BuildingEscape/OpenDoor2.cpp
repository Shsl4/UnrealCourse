// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor2.h"


// Sets default values for this component's properties
UOpenDoor2::UOpenDoor2()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor2::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();

	TriggerMass = 1.0f;

	OpenTriggerMass = 130.0f;
	
}


// Called every frame
void UOpenDoor2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetTotalMassOfActorsOnClosePlate() > TriggerMass)
	{

		OnCloseRequest.Broadcast();

	}

	if (GetTotalMassOfActorsOnOpenPlate() == OpenTriggerMass)
	{

		OnOpenRequest.Broadcast();

	}
}


float UOpenDoor2::GetTotalMassOfActorsOnClosePlate() {

	float TotalMass = 0.0f;

	TArray<AActor*> OverlappingActors;

	ClosePressurePlate->GetOverlappingActors(OUT OverlappingActors);

	for (const AActor* Actor : OverlappingActors) {

		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();

	}

	return TotalMass;

}

float UOpenDoor2::GetTotalMassOfActorsOnOpenPlate() {

	float OpenTotalMass = 0.0f;

	TArray<AActor*> OverlappingActors;

	OpenPressurePlate->GetOverlappingActors(OUT OverlappingActors);

	for (const AActor* Actor : OverlappingActors) {

		OpenTotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();

	}

	return OpenTotalMass;

}