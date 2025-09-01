// Copyright (c) 2025, Izabella Szabo. All rights reserved.

#include "ArenaShardsGameManager.h"
#include "ArenaShardsGameState.h"
#include "Activatable/ArenaShardsActivatableBase.h"

AArenaShardsGameManager::AArenaShardsGameManager()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
}

void AArenaShardsGameManager::BeginPlay()
{
	Super::BeginPlay();

	if (auto gs = Cast<AArenaShardsGameState>(GetWorld()->GetGameState()))
	{
		gs->OnCountdownStarted.AddDynamic(this, &AArenaShardsGameManager::HandleMatchCountdown);
		gs->OnMatchStart.AddDynamic(this, &AArenaShardsGameManager::HandleMatchStart);
		gs->OnMatchEnd.AddDynamic(this, &AArenaShardsGameManager::HandleMatchEnd);
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

void AArenaShardsGameManager::HandleMatchEnd(APlayerState* WinningPlayer)
{
	UE_LOG(LogTemp, Log, TEXT("Match ended! Deactivating spawners"));
	for (AArenaShardsActivatableBase* a : ActorsToActivateOnStart)
	{
		a->OnDeactivated();
	}
}
