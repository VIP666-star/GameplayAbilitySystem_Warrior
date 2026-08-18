// A Gas Demo


#include "Character/WarriorHeroCharacter.h"

#include "DebugHelper.h"

AWarriorHeroCharacter::AWarriorHeroCharacter()
{
	
}

void AWarriorHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	Debug::Print(TEXT("Hello"));
}
