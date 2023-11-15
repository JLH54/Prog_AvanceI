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
	Inventory.Add(PotionItem);
}

void AAvatar_Player::Drink()
{
	if (Inventory.Num() <= 0) return;
	if (GetHealth() >= GetMaxHealth()) return;
	if (isDead()) return;
	UPotion* PotionToDrink = Inventory.Pop();
	Heal(PotionToDrink);
}

void AAvatar_Player::Interact()
{
	//if (isDead()) return;
	OnInteractionEvent.Broadcast();
}

int AAvatar_Player::numberOfPotionInventory()
{
	return Inventory.Num();
}

void AAvatar_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
