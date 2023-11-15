// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

class AAvatar;

UCLASS()
class SOULZ_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	UPROPERTY(VisibleAnywhere)
	USceneComponent* sceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* WeaponMesh;

	void BeginDamage(AAvatar* Holder);
	void EndDamage();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void OnActorDamage(AActor* Other);

private:
	bool isAttacking;

	UPROPERTY()
	TArray<AActor*> IgnoredActors;
};
