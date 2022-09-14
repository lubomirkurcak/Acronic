// Fill out your copyright notice in the Description page of Project Settings.


#include "EarthMoonSystem.h"
#include "Kismet/KismetMathLibrary.h"
#include "Acronic.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
AEarthMoonSystem::AEarthMoonSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SatelliteCount = 3;

	USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);

	Satellites = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Satellites"));
	Satellites->SetupAttachment(SceneComponent);
}

void AEarthMoonSystem::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	UE_LOG(LogAcronic, Log, TEXT("AEarthMoonSystem::OnConstruction Creating %d satellites (%x)"), SatelliteCount, this);

	ActiveSatelliteCount = SatelliteCount;

	Satellites->ClearInstances();

	for (int i = 0; i < SatelliteCount; ++i)
	{
		float theta = 2 * PI * (float)i / SatelliteCount;

		FQuat4d Rotation = UKismetMathLibrary::RandomRotator(true).Quaternion();
		FVector Translation(PlanetRadius*cos(theta), PlanetRadius*sin(theta), 0);
		FVector Scale(1, 1, 1);
		Satellites->AddInstance(FTransform(Rotation, Translation, Scale));
	}
}

// Called when the game starts or when spawned
void AEarthMoonSystem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEarthMoonSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

