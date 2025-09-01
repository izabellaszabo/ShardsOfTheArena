// Copyright (c) 2025, Izabella Szabo. All rights reserved.

#pragma once

#include "GameFramework/GameStateBase.h"
#include "ArenaShardsGameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCountdownStarted, float, SecToStart);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMatchStart);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMatchEnd, APlayerState*, WinningPlayer);

/**
 * 
 */
UCLASS()
class ARENASHARDS_API AArenaShardsGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	// Called when the countdown to match start begins
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnCountdownStarted OnCountdownStarted;

	// Called when the match officially starts
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnMatchStart OnMatchStart;

	// Called when the match officially ends
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnMatchEnd OnMatchEnd;

	void GameCountdownStarted(float SecondsToStart);
	void HandleMatchStart();
	void HandleMatchEnd(APlayerState* WinningPlayer);

};
