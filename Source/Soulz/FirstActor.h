// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FirstActor.generated.h"

UCLASS()
class SOULZ_API AFirstActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFirstActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;

	UPROPERTY(EditDefaultsOnly)
	float DefaultOnly;

	UPROPERTY(EditInstanceOnly)
	float InstancetOnly;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void ShowLogs();

};
