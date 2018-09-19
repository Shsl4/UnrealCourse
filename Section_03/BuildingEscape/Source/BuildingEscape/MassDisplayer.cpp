// Fill out your copyright notice in the Description page of Project Settings.

#include "MassDisplayer.h"


// Sets default values for this component's properties
UMassDisplayer::UMassDisplayer()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMassDisplayer::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMassDisplayer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	GetTotalMassOfActorsOnPlate();
}

float UMassDisplayer::GetTotalMassOfActorsOnPlate() {

	TotalMass = 0.0f;

	TArray<AActor*> OverlappingActors;

	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	for (const AActor* Actor : OverlappingActors) {

		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on Pressure plate"), *Actor->GetName())

	}

	return TotalMass;

}