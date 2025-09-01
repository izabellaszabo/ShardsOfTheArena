// Copyright (c) 2025, Izabella Szabo. All rights reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "ArenaShardsGameManager.generated.h"

UCLASS()
class ARENASHARDS_API AArenaShardsGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere)
	TArray<class AArenaShardsActivatableBase*> ActorsToActivateOnStart;

	AArenaShardsGameManager();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void HandleMatchCountdown(float CountdownTime);
	UFUNCTION()
	void HandleMatchStart();
	UFUNCTION()
	void HandleMatchEnd(APlayerState* WinningPlayer);

};
