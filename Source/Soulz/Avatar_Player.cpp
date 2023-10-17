// Fill out your copyright notice in the Description page of Project Settings.


#include "Avatar_Player.h"
#include "Potion.h"


void AAvatar_Player::Take(UPotion* PotionItem)
{
	if (!PotionItem) return;
	//PotionItem->PlayPickupSound();
	Inventory.Add(PotionItem);
}
