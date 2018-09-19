// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Engine.h"
#include "Room2Activation.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRoom2Activator);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API URoom2Activation : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URoom2Activation();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
		float TriggerMass;

	UPROPERTY(BlueprintAssignable)
		FRoom2Activator Room2Activator;

	AActor* Owner = nullptr;

	float GetTotalMassOfActorsOnPlate();
	
};
