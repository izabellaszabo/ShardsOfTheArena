// Copyright (c) 2025, Izabella Szabo. All rights reserved.

#pragma once

#include "GameFramework/PlayerState.h"
#include "ArenaShardsPlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChanged, AArenaShardsPlayerState*, PlayerState);

/**
 * 
 */
UCLASS()
class ARENASHARDS_API AArenaShardsPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnScoreChanged OnScoreChanged;

	void AddArenaScore(const float ScoreToAdd);
};
