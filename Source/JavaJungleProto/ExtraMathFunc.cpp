// Fill out your copyright notice in the Description page of Project Settings.

#include "ExtraMathFunc.h"

FVector UExtraMathFunc::RoundToNearest(float rounding, FVector position, bool roundX, bool roundY, bool roundZ)
{
	if (!roundX && !roundY && !roundZ)
		return position;
	FVector posDiv = position / rounding;
	if (roundX)
		posDiv.X = roundf(posDiv.X);
	if (roundY)
		posDiv.Y = roundf(posDiv.Y);
	if (roundZ)
		posDiv.Z = roundf(posDiv.Z);
	return posDiv * rounding;
}

FVector UExtraMathFunc::VectorMultiplyByAxis(FVector vector, float mult, bool x, bool y, bool z)
{
	if (x)
		vector.X *= mult;
	if (y)
		vector.Y *= mult;
	if (z)
		vector.Z *= mult;
	return vector;
}

float UExtraMathFunc::DistanceBetweenVectors(FVector firstPosition, FVector secondPosition)
{
	float xdist, ydist, zdist;
	xdist = powf((secondPosition.X - firstPosition.X), 2);
	ydist = powf((secondPosition.Y - firstPosition.Y), 2);
	zdist = powf((secondPosition.Z - firstPosition.Z), 2);
	return sqrtf(xdist + ydist + zdist);
}

float UExtraMathFunc::DistanceBetweenVectorsSqr(FVector firstPosition, FVector secondPosition)
{
	float xdist, ydist, zdist;
	xdist = powf((secondPosition.X - firstPosition.X), 2);
	ydist = powf((secondPosition.Y - firstPosition.Y), 2);
	zdist = powf((secondPosition.Z - firstPosition.Z), 2);
	return (xdist + ydist + zdist);
}

FVector UExtraMathFunc::GetCardinalOffset(ECardinalDir direction)
{
	FVector offset(0.f);
	switch (direction)
	{
	case ECardinalDir::CD_North:
		offset.X = 200.0f;
		break;
	case ECardinalDir::CD_East:
		offset.Y = 200.0f;
		break;
	case ECardinalDir::CD_South:
		offset.X = -200.0f;
		break;
	case ECardinalDir::CD_West:
		offset.Y = -200.0f;
		break;
	default:
		break;
	}
	return offset;
}

FRotator UExtraMathFunc::GetCardinalDirection(ECardinalDir direction)
{
	FRotator rot(0.f);
	switch (direction)
	{
	case ECardinalDir::CD_North:
		rot.Yaw = 0.0f;
		break;
	case ECardinalDir::CD_East:
		rot.Yaw = 90.0f;
		break;
	case ECardinalDir::CD_South:
		rot.Yaw = 180.0f;
		break;
	case ECardinalDir::CD_West:
		rot.Yaw = 270.0f;
		break;
	default:
		break;
	}
	return rot;
}

ECardinalDir UExtraMathFunc::InvertCardinal(ECardinalDir direction)
{
	switch (direction)
	{
	case ECardinalDir::CD_North:
		return ECardinalDir::CD_South;
	case ECardinalDir::CD_East:
		return ECardinalDir::CD_West;
	case ECardinalDir::CD_South:
		return ECardinalDir::CD_North;
	case ECardinalDir::CD_West:
		return ECardinalDir::CD_East;
	default:
		return ECardinalDir::CD_North;
	}
}

bool UExtraMathFunc::IsOnSamePlane(ECardinalDir a, ECardinalDir b)
{
	switch (a)
	{
	case ECardinalDir::CD_North:
	case ECardinalDir::CD_South:
		if (b == ECardinalDir::CD_North || b == ECardinalDir::CD_South)
			return true;
		else return false;
	case ECardinalDir::CD_East:
	case ECardinalDir::CD_West:
		if (b == ECardinalDir::CD_East || b == ECardinalDir::CD_West)
			return true;
		else return false;
	default:
		return false;
	}
}

