#include "TriggerTrap.h"
#include "Avatar_Player.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
ATriggerTrap::ATriggerTrap()
{
	MinDamage = 0.0f;
	MaxDamage = 0.0f;
	PrimaryActorTick.bCanEverTick = false;

}

bool ATriggerTrap::TriggerTrap(AActor* other)
{
	if (!other) return false;
	AAvatar_Player* OtherAvatar = Cast< AAvatar_Player>(other);
	if (!OtherAvatar) return false;

	if (OtherAvatar->isDead()) return false;

	const float TotalDamage = FMath::RandRange(MinDamage, MaxDamage);
	UGameplayStatics::ApplyDamage(OtherAvatar,TotalDamage, nullptr, this, UDamageType::StaticClass());

	return true;
}