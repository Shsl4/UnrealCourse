// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "Components/ActorComponent.h"
#include "RedChairControl.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRedReceiver);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API URedChairControl : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URedChairControl();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UPROPERTY(EditAnywhere)
		ATriggerVolume* RedPlate = nullptr;

	UPROPERTY(BlueprintAssignable)
		FRedReceiver RedReceiver;

	AActor* Owner;
		
	
};
