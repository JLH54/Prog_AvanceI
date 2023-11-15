// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Avatar.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	IgnoredActors.Empty();
	sceneRoot = CreateDefaultSubobject<USceneComponent>(FName("sceneRoot"));
	SetRootComponent(sceneRoot);

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("WeaponMesh"));
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponMesh->SetupAttachment(sceneRoot);
}

void AWeapon::BeginDamage(AAvatar* Holder)
{
	isAttacking = true;
	IgnoredActors.Add(Holder);
	IgnoredActors.Empty();
}

void AWeapon::EndDamage()
{
	isAttacking = false;
	IgnoredActors.Empty();
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	isAttacking = false;
}

void AWeapon::OnActorDamage(AActor* Other)
{
	if (!isAttacking) return;
	if (Other) {
		if (!IgnoredActors.Contains(Other)) {

			IgnoredActors.Add(Other);
		}
	}
}

