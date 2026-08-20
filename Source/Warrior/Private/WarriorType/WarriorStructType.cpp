// A Gas Demo


#include "WarriorType/WarriorStructType.h"
#include "AbilitySystem/Ability/WarriorGameplayAbility.h"

bool FWarriorHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
