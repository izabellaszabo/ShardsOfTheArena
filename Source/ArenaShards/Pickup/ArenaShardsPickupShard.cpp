// Fill out your copyright notice in the Description page of Project Settings.
#include "Pickup/ArenaShardsPickupShard.h"
#include "ArenaShardsCharacter.h"

void AArenaShardsPickupShard::HandlePickup(AActor* PickedUpBy)
{
	Super::HandlePickup(PickedUpBy);
	auto player = Cast<AArenaShardsCharacter>(PickedUpBy);
	player->AddPoints(ShardPoints);	
}