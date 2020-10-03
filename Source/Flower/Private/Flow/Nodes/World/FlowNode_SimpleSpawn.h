#pragma once

#include "GameplayTagContainer.h"

#include "Nodes/FlowNode.h"

#include "Components/SpawnComponent.h"
#include "FlowNode_SimpleSpawn.generated.h"

/**
 * Simple Spawn
 */
UCLASS(NotBlueprintable, meta = (DisplayName = "Simple Spawn"))
class UFlowNode_SimpleSpawn final : public UFlowNode
{
	GENERATED_UCLASS_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = "Spawn Point")
	FGameplayTag IdentityTag;

	UPROPERTY(EditDefaultsOnly, Category = "Spawn", meta = (ShowOnlyInnerProperties))
	FFlowerSpawnParams SpawnParams;

	TSet<TWeakObjectPtr<USpawnComponent>> SpawnComponents;
	
protected:
	virtual void ExecuteInput(const FName& PinName) override;
	virtual void Cleanup() override;
	
#if WITH_EDITOR
public:
	virtual FString GetNodeDescription() const override;
#endif
};
