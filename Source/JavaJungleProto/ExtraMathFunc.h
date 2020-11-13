// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/World.h"
#include "Classes/GameFramework/Actor.h"
#include "Engine/Classes/Kismet/KismetMathLibrary.h"
// #include "GameFramework/Character.h"
// #include "AI/NavigationSystemBase.h"
// #include "NavigationSystem/Public/NavigationSystem.h"
// #include "NavigationSystemTypes.h"
#include "ExtraMathFunc.generated.h"

UENUM(BlueprintType)
enum class ECardinalDir : uint8
{
	CD_North	UMETA(DisplayName = "North"),
	CD_East		UMETA(DisplayName = "East"),
	CD_South	UMETA(DisplayName = "South"),
	CD_West		UMETA(DisplayName = "West")
};

/**
 * 
 */
UCLASS()
class JAVAJUNGLEPROTO_API UExtraMathFunc : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		// Rounds given vector to a specified rounding value.
		UFUNCTION(BlueprintPure, Category = "Math|Vector")
		static FVector RoundToNearest(float rounding, FVector position, bool roundX, bool roundY, bool roundZ);

		UFUNCTION(BlueprintPure, Category = "Math|Vector")
		static FVector VectorMultiplyByAxis(FVector vector, float mult, bool x, bool y, bool z);

		// Gets distance between 2 vectors.
		UFUNCTION(BlueprintPure, Category = "Math|Vector")
		static float DistanceBetweenVectors(FVector firstPosition, FVector secondPosition);

		// Gets Squared distance between 2 vectors. More efficient than DistanceBetweenVectors.
		UFUNCTION(BlueprintPure, Category = "Math|Vector")
		static float DistanceBetweenVectorsSqr(FVector firstPosition, FVector secondPosition);

		// Get Vector offset based on ECardinal enum with optional scale.
		UFUNCTION(BlueprintPure, Category = "Enum")
		static FVector GetCardinalOffset(ECardinalDir direction);

		UFUNCTION(BlueprintPure, Category = "Enum")
		static FRotator	GetCardinalDirection(ECardinalDir direction);

		// Flips given cardinal dir to the opposite side.
		UFUNCTION(BlueprintPure, Category = "Enum")
		static ECardinalDir InvertCardinal(ECardinalDir direction);

		UFUNCTION(BlueprintPure, Category = "Enum")
		static bool IsOnSamePlane(ECardinalDir a, ECardinalDir b);
};
