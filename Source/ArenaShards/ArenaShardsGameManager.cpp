// Copyright (c) 2025, Izabella Szabo. All rights reserved.

#include "ArenaShardsGameManager.h"
#include "ArenaShardsGameMode.h"
#include "Activatable/ArenaShardsActivatableBase.h"

AArenaShardsGameManager::AArenaShardsGameManager()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
}

void AArenaShardsGameManager::BeginPlay()
{
	Super::BeginPlay();

	if (AArenaShardsGameMode* gm = Cast<AArenaShardsGameMode>(GetWorld()->GetAuthGameMode()))
	{
		gm->OnMatchCountdown.AddDynamic(this, &AArenaShardsGameManager::HandleMatchCountdown);
		gm->OnMatchStart.AddDynamic(this, &AArenaShardsGameManager::HandleMatchStart);
	}
}

void AArenaShardsGameManager::HandleMatchCountdown(float CountdownTime)
{
	UE_LOG(LogTemp, Log, TEXT("Match countdown started %f!"), CountdownTime);
	// TODO: UI countdown or sound cue
}

void AArenaShardsGameManager::HandleMatchStart()
{
	UE_LOG(LogTemp, Log, TEXT("Match started! Activating spawners"));
	for(AArenaShardsActivatableBase* a : ActorsToActivateOnStart)
	{
		a->OnActivated();
	}
}
