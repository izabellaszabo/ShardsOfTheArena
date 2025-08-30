// Fill out your copyright notice in the Description page of Project Settings.
#include "Gameplay/Pickup/ArenaShardsPickupBase.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AArenaShardsPickupBase::AArenaShardsPickupBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	// create the base plate
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	BaseMesh->SetupAttachment(RootComponent);
	BaseMesh->SetCollisionProfileName(FName("OverlapAllDynamic"));
	BaseMesh->OnComponentBeginOverlap.AddDynamic(this, &AArenaShardsPickupBase::OnOverlap);
}

// Called when the game starts or when spawned
void AArenaShardsPickupBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArenaShardsPickupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AArenaShardsPickupBase::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OnPickup(OtherActor);
	OnPickedUp(OtherActor);
	// Pool Object

	BaseMesh->SetVisibility(false);
	BaseMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AArenaShardsPickupBase::OnPickup(AActor* PickedUpBy)
{
	
}