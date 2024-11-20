// Copyright Igorcolonna


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

/* Original Solution
 * 
UE_DEFINE_GAMEPLAY_TAG(TAG_Attributes_Primary_Strength, "Attributes.Primary.Strength")
UE_DEFINE_GAMEPLAY_TAG(TAG_Attributes_Primary_Intelligence, "Attributes.Primary.Intelligence")
UE_DEFINE_GAMEPLAY_TAG(TAG_Attributes_Primary_Resilience, "Attributes.Primary.Resilience")
UE_DEFINE_GAMEPLAY_TAG(TAG_Attributes_Primary_Vigor, "Attributes.Primary.Vigor")

UE_DEFINE_GAMEPLAY_TAG(TAG_Attributes_Secondary_Armor, "Attributes.Secondary.Armor")
UE_DEFINE_GAMEPLAY_TAG(TAG_Attributes_Secondary_ArmorPenetration, "Attributes.Secondary.ArmorPenetration")
UE_DEFINE_GAMEPLAY_TAG(TAG_Attributes_Secondary_BlockChance, "Attributes.Secondary.BlockChance")
UE_DEFINE_GAMEPLAY_TAG(TAG_Attributes_Secondary_CriticalHitChance, "Attributes.Secondary.CriticalHitChance")
UE_DEFINE_GAMEPLAY_TAG(TAG_Attributes_Secondary_CriticalHitDamage, "Attributes.Secondary.CriticalHitDamage")
UE_DEFINE_GAMEPLAY_TAG(TAG_Attributes_Secondary_CriticalHitResistance, "Attributes.Secondary.CriticalHitResistance")
UE_DEFINE_GAMEPLAY_TAG(TAG_Attributes_Secondary_HealthRegeneration, "Attributes.Secondary.HealthRegeneration")
UE_DEFINE_GAMEPLAY_TAG(TAG_Attributes_Secondary_ManaRegeneration, "Attributes.Secondary.ManaRegeneration")
UE_DEFINE_GAMEPLAY_TAG(TAG_Attributes_Secondary_MaxHealth, "Attributes.Secondary.MaxHealth")
UE_DEFINE_GAMEPLAY_TAG(TAG_Attributes_Secondary_MaxMana, "Attributes.Secondary.MaxMana")
*/

#define ADDNATIVETAG(AttributeType, AttributeName, Description)									\
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_##AttributeType##_##AttributeName,				\
		*FString((FString("Attributes.") + #AttributeType + FString(".") + #AttributeName)), Description)

ADDNATIVETAG(Primary, Strength, "Increases physical damage and armor resistance")
ADDNATIVETAG(Primary, Intelligence, "Boosts magical damage and mana capacity")
ADDNATIVETAG(Primary, Resilience, "Enhances damage resistance and block chance")
ADDNATIVETAG(Primary, Vigor, "Raises maximum health and health regeneration")

ADDNATIVETAG(Secondary, Armor, "Reduces damage from physical attacks")
ADDNATIVETAG(Secondary, ArmorPenetration, "Bypasses a portion of the enemy’s armor")
ADDNATIVETAG(Secondary, BlockChance, "Chance to block attacks, reducing their impact")
ADDNATIVETAG(Secondary, CriticalHitChance, "Probability of dealing critical damage")
ADDNATIVETAG(Secondary, CriticalHitDamage, "Increases the damage of critical hits")
ADDNATIVETAG(Secondary, CriticalHitResistance, "Reduces the effect of incoming critical hits")
ADDNATIVETAG(Secondary, HealthRegeneration, "Restores health over time")
ADDNATIVETAG(Secondary, ManaRegeneration, "Restores mana over time")
ADDNATIVETAG(Secondary, MaxHealth, "Defines the player's maximum health")
ADDNATIVETAG(Secondary, MaxMana, "Defines the player's maximum mana")

ADDNATIVETAG(Vital, Health, "How much damage the player can take before death")
ADDNATIVETAG(Vital, Mana, "Resource for spells")


FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{

#define ADDTAGTO_CONTAINER(AttributeType, AttributeName) GameplayTags.AuraTagsContainer.AddTag(Attributes_##AttributeType##_##AttributeName);

	ADDTAGTO_CONTAINER(Primary, Strength)
	ADDTAGTO_CONTAINER(Primary, Intelligence)
	ADDTAGTO_CONTAINER(Primary, Resilience)
	ADDTAGTO_CONTAINER(Primary, Vigor)

	ADDTAGTO_CONTAINER(Secondary, Armor)
	ADDTAGTO_CONTAINER(Secondary, ArmorPenetration)
	ADDTAGTO_CONTAINER(Secondary, BlockChance)
	ADDTAGTO_CONTAINER(Secondary, CriticalHitChance)
	ADDTAGTO_CONTAINER(Secondary, CriticalHitDamage)
	ADDTAGTO_CONTAINER(Secondary, CriticalHitResistance)
	ADDTAGTO_CONTAINER(Secondary, HealthRegeneration)
	ADDTAGTO_CONTAINER(Secondary, ManaRegeneration)
	ADDTAGTO_CONTAINER(Secondary, MaxHealth)
	ADDTAGTO_CONTAINER(Secondary, MaxMana)

	ADDTAGTO_CONTAINER(Vital, Health)
	ADDTAGTO_CONTAINER(Vital, Mana)

#undef ADDTAGTO_CONTAINER
	
}

#undef ADDNATIVETAG
