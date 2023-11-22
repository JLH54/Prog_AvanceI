// Fill out your copyright notice in the Description page of Project Settings.


#include "Avatar.h"
#include "Weapon.h"
#include "Engine/SkeletalMeshSocket.h"


// Sets default values
AAvatar::AAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MaxHealth = 100;
	CurrentHealth = MaxHealth;
	dying = false;
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

void AAvatar::Heal(UPotion* potion)
{
	float healAmount = MaxHealth * (potion->HealingPercent / 100.0f);

	CurrentHealth = FMath::Min(CurrentHealth + healAmount, MaxHealth);
}

float AAvatar::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	MaxHealth = GetMaxHealth();
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, MaxHealth);
	OnUpdateHealth();
	if(isDead()) return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	if (CurrentHealth <= 0) {
		CurrentHealth = 0;
		UAnimInstance* anim = GetMesh()->GetAnimInstance();
		if (!anim) return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
		if (!DeathMontage) return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
		anim->Montage_Play(DeathMontage);
		dying = true;
		
		
	}
	return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
}

void AAvatar::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = GetMaxHealth();

	if (StartingWeaponClass) {
		UWorld* World = GetWorld();
		CurrentWeapon = World->SpawnActor<AWeapon>(StartingWeaponClass);

		USkeletalMeshComponent* SM = GetMesh();
		if (!SM) return;
		const USkeletalMeshSocket* Socket = SM->GetSocketByName(FName("RightHandSocket"));
		if (!Socket)return;
		Socket->AttachActor(CurrentWeapon, SM);
	}
	
}

void AAvatar::BeginAttack()
{
	if (!CurrentWeapon) return;
	CurrentWeapon->BeginDamage(this);
}

void AAvatar::EndAttack()
{
	if (!CurrentWeapon) return;
	CurrentWeapon->EndDamage();
}

void AAvatar::NormalAttack()
{
	UAnimInstance* anim = GetMesh()->GetAnimInstance();
	if (!anim) return;
	if (!AttackMontage)return;
	anim->Montage_Play(AttackMontage);
	anim->Montage_JumpToSection(FName("Normal"));
}

// Called every frame
void AAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}