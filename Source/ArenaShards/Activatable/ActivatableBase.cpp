// Fill out your copyright notice in the Description page of Project Settings.
#include "Activatable/ActivatableBase.h"
#include "Components/BillboardComponent.h"

AActivatableBase::AActivatableBase()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Visualization = CreateDefaultSubobject<UBillboardComponent>(TEXT("Visualization"));
	Visualization->SetupAttachment(RootComponent);
	Visualization->SetHiddenInGame(true);
}

void AActivatableBase::BeginPlay()
{
	Super::BeginPlay();

	switch (StartState)
	{
		case EActivatorState::Inactive:
			break;
		case EActivatorState::Activated:
			OnActivated();
			break;
		case EActivatorState::Deactivated:
			OnDeactivated();
			break;
		default:
			break;
	}
}

void AActivatableBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActivatableBase::Activate()
{
	for(AActivatableBase* a : ActorsToActivate)
	{
		if (IsValid(a))
		{
			if(a->State != EActivatorState::Activated || (a->State == EActivatorState::Activated && a->MultipleActivationsAllowed))
				a->OnActivated();
		}
	}
}

void AActivatableBase::Deactivate()
{
	for (AActivatableBase* a : ActorsToDeactivate)
	{
		if (IsValid(a))
		{
			if (a->State != EActivatorState::Deactivated || (a->State == EActivatorState::Deactivated && a->MultipleDeactivationsAllowed))
				a->OnDeactivated();
		}
	}
}

void AActivatableBase::OnActivated()
{
	State = EActivatorState::Activated;
	BP_OnActivated();
}

void AActivatableBase::OnDeactivated()
{
	State = EActivatorState::Deactivated;
	BP_OnDeactivated();
}
