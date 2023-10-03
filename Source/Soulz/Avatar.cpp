// Fill out your copyright notice in the Description page of Project Settings.


#include "Avatar.h"

// Sets default values
AAvatar::AAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

float AAvatar::GetHealth()
{
	return CurrentHealth;
}

float AAvatar::GetMaxHealth()
{
	/*if (Attribute) {
		return Attribute->MaxHealth;
	}*/
	return 0.0f;
}

float AAvatar::GetPercentHealth()
{
	float MaxHealth = GetMaxHealth();
	if (MaxHealth > 0) {
		return CurrentHealth / MaxHealth;
	}
	return 0.0f;
}

float AAvatar::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float MaxHealth = GetMaxHealth();
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, MaxHealth);
	OnUpdateHealth();
	if (CurrentHealth == 0) {
		/*APaladinController* PaladinController = Cast<APaladinController>(GetController());
		if (!PaladinController) return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);;
		PaladinController->Dying = true;
		USkeletalMeshComponent* MeshComponent = GetMesh();
		if (!MeshComponent) return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);;
		UPaladinAnimInstance* AnimInstance = Cast<UPaladinAnimInstance>(MeshComponent->GetAnimInstance());
		if (!AnimInstance) return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);;
		AnimInstance->Dying = true;*/
	}
	return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
}

// Called when the game starts or when spawned
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

// Called to bind functionality to input
//void AAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

