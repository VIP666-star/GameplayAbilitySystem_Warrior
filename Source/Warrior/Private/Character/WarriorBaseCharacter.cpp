// A Gas Demo


#include "Character/WarriorBaseCharacter.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/WarriorAttributeSet.h"

AWarriorBaseCharacter::AWarriorBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	
	GetMesh()->bReceivesDecals = false;

	WarriorAbilitySystemComponent = CreateDefaultSubobject<UWarriorAbilitySystemComponent>("WarriorAbilitySystemComponent");
	
	WarriorAttributeSet = CreateDefaultSubobject<UWarriorAttributeSet>("WarriorAttributeSet");
}

UAbilitySystemComponent* AWarriorBaseCharacter::GetAbilitySystemComponent() const
{
	return GetWarriorAbilitySystemComponent();
}

void AWarriorBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	if (WarriorAbilitySystemComponent)
	{
		WarriorAbilitySystemComponent->InitAbilityActorInfo(this, this);
		
		ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("CharacterStartUpData is nullptr in %s"), *GetName());
	}
}