// Fill out your copyright notice in the Description page of Project Settings.


#include "AdditionalAmmo.h"
#include "ShooterCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"



// Sets default values
AAdditionalAmmo::AAdditionalAmmo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// All pickups start active
	bIsActive = true;

	//Create the static mesh component 
	AmmoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ammo Mesh"));
	AmmoMesh->SetupAttachment(CollisionComp);
	
	// Create the root BoxComponent to handle the pickup's collision
	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	SetRootComponent(CollisionComp);
	CollisionComp->SetCollisionProfileName(TEXT("OverlapAll"));
	CollisionComp->SetGenerateOverlapEvents(true);

}

// Called when the game starts or when spawned
void AAdditionalAmmo::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AAdditionalAmmo::OverlapBegin);
}

// Called every frame
void AAdditionalAmmo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAdditionalAmmo::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
					  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
					  bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		OverlappedComponent->DestroyComponent();
		AmmoMesh->SetVisibility(false);
		ShooterCharacter = Cast<AShooterCharacter>(OtherActor);
		ShooterCharacter->SetGunAmount(10);
	}
}

