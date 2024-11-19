// Copyright Igorcolonna

#pragma once

#include "CoreMinimal.h"
#incluce "GameplayTagContainer.h"

/**
 *  AuraGameplayTags
 *
 *  Singleton containg native Gameplay Tags
 */

struct FAuraGameplayTags
{
public:
 static const FAuraGameplayTags& Get() {return GameplayTags;}
 static void InitializeNativeGameplayTags();
private:

protected:
 static FAuraGameplayTags GameplayTags;
};
