// Copyright (c) 2025, Izabella Szabo. All rights reserved.

#include "Pickup/ArenaShardsPickupShard.h"
#include "ArenaShardsCharacter.h"

void AArenaShardsPickupShard::HandlePickup(AActor* PickedUpBy)
{
	Super::HandlePickup(PickedUpBy);
	auto player = Cast<AArenaShardsCharacter>(PickedUpBy);
	player->AddPoints(ShardPoints);	
}