// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArenaShardsPickupBase.h"
#include "ArenaShardsPickupShard.generated.h"

/**
 * 
 */
UCLASS()
class ARENASHARDS_API AArenaShardsPickupShard : public AArenaShardsPickupBase
{
	GENERATED_BODY()
	
public: 
	UPROPERTY(EditDefaultsOnly, Category = "Shard")
	int ShardPoints = 1;

	virtual void HandlePickup(AActor* PickedUpBy);

};
