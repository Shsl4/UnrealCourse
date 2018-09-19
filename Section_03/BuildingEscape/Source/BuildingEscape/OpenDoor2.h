// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Engine.h"
#include "OpenDoor2.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest2);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCloseRequest2);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor2 : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor2();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UPROPERTY(EditAnywhere)
		ATriggerVolume* OpenPressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* ClosePressurePlate = nullptr;

	UPROPERTY(BlueprintAssignable)
		FOnOpenRequest2 OnOpenRequest;

	UPROPERTY(BlueprintAssignable)
		FOnCloseRequest2 OnCloseRequest;

	float GetTotalMassOfActorsOnOpenPlate();

	float GetTotalMassOfActorsOnClosePlate();

	float TriggerMass;

	float OpenTriggerMass;

	AActor* Owner = nullptr;	
};
