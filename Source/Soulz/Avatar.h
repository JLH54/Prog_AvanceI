#pragma once
#include "Potion.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Avatar.generated.h"

class AWeapon;

UCLASS()
class SOULZ_API AAvatar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAvatar();

	UFUNCTION(BlueprintCallable)
	float GetHealth();

	UFUNCTION(BlueprintCallable)
	float GetMaxHealth();

	UFUNCTION(BlueprintCallable)
	float GetPercentHealth();

	UFUNCTION(BlueprintCallable)
	bool isDead() const;

	void Heal(UPotion* potion);

	virtual float TakeDamage(float Damage,
		struct FDamageEvent
		const& DamageEvent,
		AController* EventInstigator
		, AActor* DamageCauser) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateHealth();

	UPROPERTY();
	AWeapon* CurrentWeapon;

	UPROPERTY(EditAnywhere);
	TSubclassOf<AWeapon> StartingWeaponClass;

	UFUNCTION(BlueprintCallable)
	void BeginAttack();
	UFUNCTION(BlueprintCallable)
	void EndAttack();
	UFUNCTION(BlueprintCallable)
	void NormalAttack();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	float CurrentHealth;

	UPROPERTY(EditAnywhere)
	float MaxHealth;

	UPROPERTY(EditAnywhere, Category = "Dying")
	bool dying;

protected:
	UPROPERTY(EditAnywhere)
	UAnimMontage* DeathMontage;

	UPROPERTY(EditAnywhere)
	UAnimMontage* AttackMontage;

};
