// Copyright Igorcolonna


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "AuraGameplayTags.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"

void UAttributeMenuWidgetController::BindCallbackToDependencies()
{
	
	check(AttributeInfo);

	for(FAuraAttributeInfo& Info : AttributeInfo->AttributeInformation)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Info.AttributeToGet).AddLambda(
			[this, Info](const FOnAttributeChangeData& Data)
			{
				BroadcastAttributeInfo(Info.AttributeTag);
			});
	}
	
}

// Alternative solution
void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& Tag) const
{
	// Getting info from DataAsset AttributeInfo base on the GameplayTag
	FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(Tag);
	//Set the hidden value in AttributeInfo DataAsset
	Info.AttributeValue = Info.AttributeToGet.GetNumericValue(AttributeSet);
	//Broadcast for those who can subscribe. IE the attribute menu widget in blueprint
	AttributeInfoDelegate.Broadcast(Info);
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	check(AttributeInfo);
	for (FAuraAttributeInfo& Info : AttributeInfo->AttributeInformation)
	{
		BroadcastAttributeInfo(Info.AttributeTag);
	}
	
}

// Original Solution
void UAttributeMenuWidgetController::BroadcastAttributeInfoOrg(const FGameplayTag& AttributeTag,
	const FGameplayAttribute& Attribute) const
{
	
	FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}
