// Fill out your copyright notice in the Description page of Project Settings.


#include "Potion.h"
#include "Avatar_Player.h"
#include "Kismet/GameplayStatics.h"

UPotion::UPotion()
{
	HealingPercent = 0.0f;
}

bool UPotion::Drink(AAvatar_Player* Avatar)
{
	if (!Avatar) return false;
	return true;
}

void UPotion::PlayPickupSound(const FVector& Location)
{
	if (!PickUpSound) return;
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), PickUpSound, Location);
}
