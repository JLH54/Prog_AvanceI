// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstActor.h"

// Sets default values
AFirstActor::AFirstActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("FirstActor CTor"));

	Speed = 100.0f;

}

// Called when the game starts or when spawned
void AFirstActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("FirstActor Begin Play"));
}

// Called every frame
void AFirstActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("FirstActor Tick"));
	//SetActorTickEnabled(false);

	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += GetActorForwardVector() * Speed * DeltaTime;
	SetActorLocation(CurrentLocation);

}

void AFirstActor::ShowLogs()
{
	const int32 MyInt = 5;
	const float MyFloat = 12.345f;
	const FString MyString = "Hello";
	const FVector MyVector(1.0f, 2.0f, 3.0f);
	const bool MyBool = true;

	UE_LOG(LogTemp, Warning, TEXT("MyInt : %d"), MyInt);
	UE_LOG(LogTemp, Warning, TEXT("MyFloat : %f"), MyFloat);
	UE_LOG(LogTemp, Warning, TEXT("MyString : %s"), *MyString);
	UE_LOG(LogTemp, Warning, TEXT("MyVector : %s"), *MyVector.ToString());
	UE_LOG(LogTemp, Warning, TEXT("MyBool : %s"), MyBool ? TEXT("true") : TEXT("false"));
	UE_LOG(LogTemp, Warning, TEXT("MyBool : %s"), MyBool);
}

