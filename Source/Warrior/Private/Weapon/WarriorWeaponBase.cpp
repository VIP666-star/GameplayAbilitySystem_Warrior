// A Gas Demo


#include "Weapon/WarriorWeaponBase.h"

#include "Components/BoxComponent.h"

AWarriorWeaponBase::AWarriorWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("WeaponMesh");
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SetRootComponent(WeaponMesh);
	
	WeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>("WeaponCollisionBox");
	WeaponCollisionBox->SetupAttachment(GetRootComponent());
	WeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

