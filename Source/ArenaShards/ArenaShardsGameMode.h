// Copyright (c) 2025, Izabella Szabo. All rights reserved.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "ArenaShardsGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMatchCountdown, float, CountdownTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMatchStart);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMatchEnd, APlayerState*, WinningPlayer);

/**
 *  
 */
UCLASS(abstract)
class AArenaShardsGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
    // Called when the countdown begins
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnMatchCountdown OnMatchCountdown;

    // Called when the match officially starts
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnMatchStart OnMatchStart;

    // Called when the match officially ends
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnMatchEnd OnMatchEnd;

    UPROPERTY(EditDefaultsOnly)
    float GameStartCountdownSec = 5.0f;

    UPROPERTY(EditDefaultsOnly)
    float MaxGameTimeSec = 300.0f;

    UPROPERTY(EditDefaultsOnly)
    float ScoreToWin = 100.0f;

    void PostLogin(APlayerController* NewPlayer) override;

protected:
    virtual void BeginPlay() override;

private:
    FTimerHandle StartTimerHandle;
    FTimerHandle GameEndTimerHandle;

    UFUNCTION()
    void CheckWinCondition(class AArenaShardsPlayerState* PlayerState);

    void StartCountdown();
    void StartMatch();
    void EndMatch();
};



