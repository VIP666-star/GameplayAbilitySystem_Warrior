// A Gas Demo

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "WarriorBaseCharacter.generated.h"

class UDataAsset_StartUpDataBase;
class UWarriorAbilitySystemComponent;
class UWarriorAttributeSet;

UCLASS()
class WARRIOR_API AWarriorBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AWarriorBaseCharacter();
	
	//~ Begin IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface
	
protected:
	//~ Begin APawn interface
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn interface
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UWarriorAbilitySystemComponent> WarriorAbilitySystemComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UWarriorAttributeSet> WarriorAttributeSet;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "StartUpData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;
	
public:
	FORCEINLINE UWarriorAbilitySystemComponent* GetWarriorAbilitySystemComponent() const { return WarriorAbilitySystemComponent; }
	FORCEINLINE UWarriorAttributeSet* GetWarriorAttributeSet() const { return WarriorAttributeSet; }
};
