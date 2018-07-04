#include <iostream>
#include "Vectors.h"

Vector4 Vector4::Vector_Vector_Addition( Vector4 Vec1, Vector4 Vec2 )
{
	Vector4 VecResult;

	VecResult.Vecx = Vec1.Vecx + Vec2.Vecx;
	VecResult.Vecy = Vec1.Vecy + Vec2.Vecy;
	VecResult.Vecz = Vec1.Vecz + Vec2.Vecz;
	VecResult.Vecw = 1.0f;

	return VecResult;
}

Vector4 Vector4::Vector_Vector_Subtraction(  Vector4 Vec1, Vector4 Vec2 )
{
	Vector4 VecResult;

	VecResult.Vecx = Vec1.Vecx - Vec2.Vecx;
	VecResult.Vecy = Vec1.Vecy - Vec2.Vecy;
	VecResult.Vecz = Vec1.Vecz - Vec2.Vecz;
		VecResult.Vecw = 1.0f;

	return VecResult;
}

Vector4 Vector4::Vector_Scalar_Multiplication( Vector4 Vec, float Sca )
{
	Vector4 VecResult;

	if ( Sca > 0 )
	{
		VecResult.Vecx = Vec.Vecx * Sca;
		VecResult.Vecy = Vec.Vecy * Sca;
		VecResult.Vecz = Vec.Vecz * Sca;
	}
	if ( Sca < 0 )
	{
		VecResult.Vecx = -(Vec.Vecx * abs(Sca));
		VecResult.Vecy = -(Vec.Vecy * abs(Sca));
		VecResult.Vecz = -(Vec.Vecz * abs(Sca));
	}

	VecResult.Vecw = 1.0f;

	return VecResult;
}

Vector4 Vector4::Vector_Scalar_Division( Vector4 Vec, float Sca )
{
	Vector4 VecResult;

	if ( Sca > 0 )
	{
		VecResult.Vecx = Vec.Vecx / Sca;
		VecResult.Vecy = Vec.Vecy / Sca;
		VecResult.Vecz = Vec.Vecz / Sca;
	}
	if ( Sca < 0 )
	{
		VecResult.Vecx = -(Vec.Vecx / abs(Sca));
		VecResult.Vecy = -(Vec.Vecy / abs(Sca));
		VecResult.Vecz = -(Vec.Vecz / abs(Sca));
	}

	VecResult.Vecw = 1.0f;

	return VecResult;
}

//float Vector4::Dot_Product ( Vector4 Vec1, Vector4 Vec2, float Angle )
//{
//	float ScalarResult;
//
//	ScalarResult = ( sqrt( ( pow(Vec1.Vecx, 2 ) ) + ( pow( Vec1.Vecy, 2 ) ) + ( pow( Vec1.Vecz, 2 ) ) ) ) * sqrt( ( pow( Vec2.Vecx, 2 ) ) + ( pow( Vec2.Vecy, 2 ) ) + ( pow( Vec2.Vecz, 2 ) ) ) * cos( Angle );
//
//	return ScalarResult;
//}

float Vector4::Dot_Product ( Vector4 Vec1, Vector4 Vec2, float Angle )
{
	float ScalarResult;

	ScalarResult = (Vec1.Vecx * Vec2.Vecx) + (Vec1.Vecy * Vec2.Vecy) + (Vec1.Vecz * Vec2.Vecz);

	return ScalarResult;
}

Vector4 Vector4::Cross_Product ( Vector4 Vec1, Vector4 Vec2 )
{
	Vector4 VecResult;

	VecResult.Vecx = ((Vec1.Vecy * Vec2.Vecz) - (Vec1.Vecz * Vec2.Vecy));
	VecResult.Vecy = ((Vec1.Vecz * Vec2.Vecx) - (Vec1.Vecx * Vec2.Vecz));
	VecResult.Vecz = ((Vec1.Vecx * Vec2.Vecy) - (Vec1.Vecy * Vec2.Vecx));
	VecResult.Vecw = 1.0f;

	return VecResult;
}