// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AdditionalAmmo.generated.h"


UCLASS()
class SHOOTER_API AAdditionalAmmo : public AActor
{
	GENERATED_BODY()


public:	
	// Sets default values for this actor's properties
	AAdditionalAmmo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// True when the pickup can be used, and false when pickup is deactivated
	bool bIsActive;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                      UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                      bool bFromSweep, const FHitResult& SweepResult);
 
private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* AmmoMesh;

	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess=true))
	class UBoxComponent* CollisionComp;

	UPROPERTY()
	class AShooterCharacter* ShooterCharacter;


};
