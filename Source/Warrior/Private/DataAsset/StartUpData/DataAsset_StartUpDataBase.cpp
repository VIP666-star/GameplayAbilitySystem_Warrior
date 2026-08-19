// A Gas Demo


#include "DataAsset/StartUpData/DataAsset_StartUpDataBase.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Ability/WarriorGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	check(InASCToGive);
	
	GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGrant, UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGrant.IsEmpty()) return;
	
	for (const TSubclassOf<UWarriorGameplayAbility>& Ability : InAbilitiesToGrant)
	{
		if (!Ability) continue;;
		
		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		
		InASCToGive->GiveAbility(AbilitySpec);
	}
}
