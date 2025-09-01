// Copyright (c) 2025, Izabella Szabo. All rights reserved.

#include "ArenaShardsGameMode.h"
#include "Gameframework/PlayerState.h"
#include "Gameframework/GameState.h"
#include "ArenaShardsPlayerState.h"
#include "ArenaShardsGameState.h"

void AArenaShardsGameMode::BeginPlay()
{
    Super::BeginPlay();

    FTimerHandle CountdownTimerHandle;
    GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &AArenaShardsGameMode::StartCountdown, 1.0f, false);
}

void AArenaShardsGameMode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    auto ps = NewPlayer->GetPlayerState<AArenaShardsPlayerState>();
    if (ps)
    {
        ps->OnScoreChanged.AddDynamic(this, &AArenaShardsGameMode::CheckWinCondition);
    }
}

void AArenaShardsGameMode::StartCountdown()
{
    auto gs = Cast<AArenaShardsGameState>(GameState);
    if(gs)
    {
        gs->GameCountdownStarted(GameStartCountdownSec);
    }
    GetWorldTimerManager().SetTimer(StartTimerHandle, this, &AArenaShardsGameMode::StartMatch, GameStartCountdownSec, false);
}

void AArenaShardsGameMode::StartMatch()
{
    auto gs = Cast<AArenaShardsGameState>(GameState);
    if (gs)
    {
        gs->HandleMatchStart();
    }
    GetWorldTimerManager().SetTimer(GameEndTimerHandle, this, &AArenaShardsGameMode::EndMatch, MaxGameTimeSec, false);
}

void AArenaShardsGameMode::CheckWinCondition(AArenaShardsPlayerState* PlayerState)
{
    if (PlayerState)
    {
        const int32 PlayerScore = PlayerState->GetScore();
        if (PlayerScore >= ScoreToWin)
        {
            EndMatch();
        }
    }
}

void AArenaShardsGameMode::EndMatch()
{
    auto gs = Cast<AArenaShardsGameState>(GameState);
    if (!gs) return;

    APlayerState* WinningPlayer = nullptr;
    int32 HighestScore = -1;

    for (APlayerState* ps : gs->PlayerArray)
    {
        if (ps)
        {
            const int32 PlayerScore = ps->GetScore(); 
            if (PlayerScore > HighestScore)
            {
                HighestScore = PlayerScore;
                WinningPlayer = ps;
                // Improvement: Handle Ties, handle zero points
            }
        }
    }

    if (WinningPlayer)
    {
        UE_LOG(LogTemp, Log, TEXT("Winner: %s with score %d"), *WinningPlayer->GetPlayerName(), HighestScore);

        if (gs)
        {
            gs->HandleMatchEnd(WinningPlayer);
        }
    }
}
