// Fill out your copyright notice in the Description page of Project Settings.


#include "Avatar.h"

// Sets default values
AAvatar::AAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	MaxHealth = 100;
	CurrentHealth = MaxHealth;
}

float AAvatar::GetHealth()
{
	return CurrentHealth;
}

float AAvatar::GetMaxHealth()
{
	return MaxHealth;
}

float AAvatar::GetPercentHealth()
{
	if (MaxHealth > 0) {
		return CurrentHealth / MaxHealth;
	}
	return 0.0f;
}

bool AAvatar::isDead() const
{
	return dying;
}

float AAvatar::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	MaxHealth = GetMaxHealth();
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, MaxHealth);
	OnUpdateHealth();
	if (CurrentHealth == 0) {
		UAnimInstance* anim = GetMesh()->GetAnimInstance();
		if (!anim) return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);;
		if (!DeathMontage) return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);;
		anim->Montage_Play(DeathMontage);
		dying = true;
	}
	return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
}

void AAvatar::BeginPlay()
{
	CurrentHealth = GetMaxHealth();
	Super::BeginPlay();
}

// Called every frame
void AAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}