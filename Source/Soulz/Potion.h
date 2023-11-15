// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Potion.generated.h"

class AAvatar_Player;

/**
 * 
 */
UCLASS(BlueprintType, BlueprintAble)
class SOULZ_API UPotion : public UObject
{
	GENERATED_BODY()

public:
	UPotion();
	bool Drink(AAvatar_Player* Avatar);

	UPROPERTY(EditAnywhere)
	float HealingPercent;
protected:
	UPROPERTY(EditAnywhere)
	USoundBase* PickUpSound;

	UPROPERTY(EditAnywhere)
	USoundBase* DrinkSound;

public:
	void PlayPickupSound(const FVector& Location);
};