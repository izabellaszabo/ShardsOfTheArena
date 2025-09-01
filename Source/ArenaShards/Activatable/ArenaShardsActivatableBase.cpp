// Copyright (c) 2025, Izabella Szabo. All rights reserved.

#include "Activatable/ArenaShardsActivatableBase.h"
#include "Components/BillboardComponent.h"

AArenaShardsActivatableBase::AArenaShardsActivatableBase()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Visualization = CreateDefaultSubobject<UBillboardComponent>(TEXT("Visualization"));
	Visualization->SetupAttachment(RootComponent);
	Visualization->SetHiddenInGame(true);
}

void AArenaShardsActivatableBase::BeginPlay()
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

void AArenaShardsActivatableBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AArenaShardsActivatableBase::Activate()
{
	for(AArenaShardsActivatableBase* a : ActorsToActivate)
	{
		if (IsValid(a))
		{
			if(a->State != EActivatorState::Activated || (a->State == EActivatorState::Activated && a->MultipleActivationsAllowed))
				a->OnActivated();
		}
	}
}

void AArenaShardsActivatableBase::Deactivate()
{
	for (AArenaShardsActivatableBase* a : ActorsToDeactivate)
	{
		if (IsValid(a))
		{
			if (a->State != EActivatorState::Deactivated || (a->State == EActivatorState::Deactivated && a->MultipleDeactivationsAllowed))
				a->OnDeactivated();
		}
	}
}

void AArenaShardsActivatableBase::OnActivated()
{
	State = EActivatorState::Activated;
	BP_OnActivated();
}

void AArenaShardsActivatableBase::OnDeactivated()
{
	State = EActivatorState::Deactivated;
	BP_OnDeactivated();
}
