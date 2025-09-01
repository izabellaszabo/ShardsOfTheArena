// Copyright (c) 2025, Izabella Szabo. All rights reserved.

#include "ArenaShardsPlayerState.h"

void AArenaShardsPlayerState::AddArenaScore(const float ScoreToAdd)
{
	SetScore(GetScore() + ScoreToAdd);
	OnScoreChanged.Broadcast(this);
}