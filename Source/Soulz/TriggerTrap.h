// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerTrap.generated.h"

UCLASS()
class SOULZ_API ATriggerTrap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATriggerTrap();

protected:
	UFUNCTION(BlueprintCallable)
	bool TriggerTrap(AActor* other);

	UPROPERTY(EditAnywhere)
	float MaxDamage;
	UPROPERTY(EditAnywhere)
	float MinDamage;

};
