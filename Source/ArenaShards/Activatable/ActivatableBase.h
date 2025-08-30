// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActivatableBase.generated.h"

UENUM(BlueprintType)
enum class EActivatorState : uint8
{
	Inactive		UMETA(DisplayName = "Inactive"),
	Activated		UMETA(DisplayName = "Actviated"),
	Deactivated		UMETA(DisplayName = "Deactivated"),
};

UCLASS()
class ARENASHARDS_API AActivatableBase : public AActor
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
	TArray<AActivatableBase*> ActorsToActivate;

	UPROPERTY(EditAnywhere, Category = "Activator")
	TArray<AActivatableBase*> ActorsToDeactivate;

	AActivatableBase();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Activate();
	UFUNCTION(BlueprintCallable)
	void Deactivate();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnActivated();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnDeactivated();

protected:
	EActivatorState State = EActivatorState::Inactive;

	virtual void BeginPlay() override;

	virtual void OnActivated();
	virtual void OnDeactivated();
	
};
