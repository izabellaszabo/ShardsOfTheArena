// Copyright (c) 2025, Izabella Szabo. All rights reserved.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "ArenaShardsGameMode.generated.h"

/**
 *  
 */
UCLASS(abstract)
class AArenaShardsGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
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



