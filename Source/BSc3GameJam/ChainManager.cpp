// Fill out your copyright notice in the Description page of Project Settings.


#include "ChainManager.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "Engine/World.h"

// Sets default values
AChainManager::AChainManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	RopeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RopeMesh"));
	RopeMesh->SetupAttachment(this->RootComponent);

	/*static ConstructorHelpers::FObjectFinder<UStaticMesh> ModelPath(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube'"));
	RopeMeshAsset = ModelPath.Object;*/
	RopeMesh->SetStaticMesh(RopeMeshAsset);
}

// Called when the game starts or when spawned
void AChainManager::BeginPlay()
{
	Super::BeginPlay();

	if (RopeMeshAsset) RopeMesh->SetStaticMesh(RopeMeshAsset);
	RopeMesh->RegisterComponent();
	FVector StartLocation = GetActorLocation();
	FRotator roc;

	//FActorSpawnParameters SpawnParameters;
	//AChainManager FirstLink = GetWorld()->SpawnActor<AChainManager>(RopeClass, StartLocation, roc, SpawnParameters);
	//if (RopeTileMesh) FirstLink->TileMeshAsset = RopeMeshAsset;
}

// Called every frame
void AChainManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChainManager::OnConstruction(const FTransform& Transform)
{
	if (RopeMeshAsset) RopeMesh->SetStaticMesh(RopeMeshAsset);


}
