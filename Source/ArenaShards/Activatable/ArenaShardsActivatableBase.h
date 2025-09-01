// Copyright (c) 2025, Izabella Szabo. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArenaShardsActivatableBase.generated.h"

UENUM(BlueprintType)
enum class EActivatorState : uint8
{
	Inactive		UMETA(DisplayName = "Inactive"),
	Activated		UMETA(DisplayName = "Actviated"),
	Deactivated		UMETA(DisplayName = "Deactivated"),
};

UCLASS()
class ARENASHARDS_API AArenaShardsActivatableBase : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBillboardComponent* Visualization;

	UPROPERTY(EditAnywhere, Category = "Activator")
	EActivatorState StartState = EActivatorState::Inactive;

	UPROPERTY(EditAnywhere, Category = "Activator")
	bool MultipleActivationsAllowed = false;

	UPROPERTY(EditAnywhere, Category = "Activator")
	bool MultipleDeactivationsAllowed = false;

	UPROPERTY(EditAnywhere, Category = "Activator")
	TArray<AArenaShardsActivatableBase*> ActorsToActivate;

	UPROPERTY(EditAnywhere, Category = "Activator")
	TArray<AArenaShardsActivatableBase*> ActorsToDeactivate;

	AArenaShardsActivatableBase();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Activate();
	UFUNCTION(BlueprintCallable)
	void Deactivate();

	virtual void OnActivated();
	virtual void OnDeactivated();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnActivated();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnDeactivated();

protected:
	EActivatorState State = EActivatorState::Inactive;

	virtual void BeginPlay() override;
	
};
