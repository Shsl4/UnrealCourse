// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "Components/ActorComponent.h"
#include "PurpleChairControl.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPurpleReceiver);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UPurpleChairControl : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPurpleChairControl();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PurplePlate = nullptr;

	UPROPERTY(BlueprintAssignable)
		FPurpleReceiver PurpleReceiver;

	AActor* Owner;

	AActor* SpawnOwner;

	bool isInPlace;
		
	
};
