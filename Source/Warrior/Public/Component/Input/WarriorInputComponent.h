// A Gas Demo

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "GameplayTagContainer.h"
#include "DataAsset/Input/DataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"

class UDataAsset_InputConfig;

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:
	template<class UserObject, typename CallBackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallBackFunc Func);
	
	template<class UserObject, typename CallBackFunc>
	void BindAbilityInputAction(const UDataAsset_InputConfig* InputConfig, UserObject* ContextObject, CallBackFunc InputPressedFunc, CallBackFunc InputReleasedFunc);
};

template <class UserObject, typename CallBackFunc>
void UWarriorInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallBackFunc Func)
{
	checkf(InputConfig, TEXT("InputConfig is nullptr in UWarriorInputComponent::BindNativeInputAction"));
	
	if (UInputAction* FoundAction = InputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
}

template <class UserObject, typename CallBackFunc>
void UWarriorInputComponent::BindAbilityInputAction(const UDataAsset_InputConfig* InputConfig, UserObject* ContextObject, CallBackFunc InputPressedFunc, CallBackFunc InputReleasedFunc)
{
	checkf(InputConfig, TEXT("InputConfig is nullptr in UWarriorInputComponent::BindAbilityInputAction"));
	
	for (const FWarriorInputActionConfig& InputActionConfig : InputConfig->AbilityInputActions)
	{
		if (!InputActionConfig.IsValid()) continue;
		
		BindAction(InputActionConfig.InputAction, ETriggerEvent::Started, ContextObject, InputPressedFunc, InputActionConfig.InputTag);
		BindAction(InputActionConfig.InputAction, ETriggerEvent::Completed, ContextObject, InputReleasedFunc, InputActionConfig.InputTag);
	}
}
