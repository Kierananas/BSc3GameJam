// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChainManager.generated.h"

UCLASS()
class BSC3GAMEJAM_API AChainManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChainManager();

	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* RopeMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
		UStaticMesh* RopeMeshAsset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
		TArray<UStaticMeshComponent*> RopeArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
		bool SimulatePhysics;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void OnConstruction(const FTransform& Transform) override;

	/*UPROPERTY(EditAnywhere)
		TSubclassOf<AChainManager> RopeClass = AChainManager::StaticClass();*/
};
