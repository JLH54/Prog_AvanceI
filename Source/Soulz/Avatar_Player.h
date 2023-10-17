// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Avatar.h"
#include "Avatar_Player.generated.h"

class UPotion;

/**
 * 
 */
UCLASS()
class SOULZ_API AAvatar_Player : public AAvatar
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable)
	void Take(UPotion* PotionItem);

	UPROPERTY(VisibleAnywhere)
	TArray<UPotion*> Inventory;
};
