// Copyright (c) 2025, Izabella Szabo. All rights reserved.

#include "ArenaShardsGameState.h"

void AArenaShardsGameState::GameCountdownStarted(float SecondsToStart)
{
	OnCountdownStarted.Broadcast(SecondsToStart);
}

void AArenaShardsGameState::HandleMatchStart()
{
	OnMatchStart.Broadcast();
}

void AArenaShardsGameState::HandleMatchEnd(APlayerState* WinningPlayer)
{
	OnMatchEnd.Broadcast(WinningPlayer);
}
