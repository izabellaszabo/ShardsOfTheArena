// Copyright (c) 2025, Izabella Szabo. All rights reserved.

#pragma once

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
