// Fill out your copyright notice in the Description page of Project Settings.

#include "Room2Activation.h"


// Sets default values for this component's properties
URoom2Activation::URoom2Activation()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URoom2Activation::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	
}


// Called every frame
void URoom2Activation::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetTotalMassOfActorsOnPlate() > TriggerMass) {

		Room2Activator.Broadcast();

	}
}

float URoom2Activation::GetTotalMassOfActorsOnPlate() {

	float TotalMass = 0.0f;

	TArray<AActor*> OverlappingActors;

	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	for (const AActor* Actor : OverlappingActors) {

		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on Pressure plate"), *Actor->GetName())

	}

	return TotalMass;

}