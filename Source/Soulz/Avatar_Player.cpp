// Fill out your copyright notice in the Description page of Project Settings.


#include "Avatar_Player.h"
#include "Potion.h"


float AAvatar_Player::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
}

void AAvatar_Player::BeginPlay()
{
	Super::BeginPlay();
}

void AAvatar_Player::Take(UPotion* PotionItem)
{
	if (!PotionItem) return;
	//PotionItem->PlayPickupSound();
	Inventory.Add(PotionItem);
}

void AAvatar_Player::Drink()
{
	if (Inventory.Num() <= 0) return;
	UPotion* PotionToDrink = Inventory.Pop();
	PotionToDrink->Drink(this);
}

void AAvatar_Player::Interact()
{
	OnInteractionEvent.Broadcast();
}

void AAvatar_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
