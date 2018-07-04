#ifndef _MATHFUNCTIONS_H_
#define _MATHFUNCTIONS_H_

#include <iostream>
#include "MathClasses.h"


//---------------VECTOR---------------\\


float Vector4::Vector_Angle ( Vector4 Vec1, Vector4 Vec2)
{
	float angle;
	float scalar;
	float Mag1;
	float Mag2;

	scalar = Dot_Product( Vec1, Vec2 );

	Mag1 = sqrt ( ( pow( Vec1.Vecx, 2 ) ) + ( pow ( Vec1.Vecy, 2 ) ) + ( pow ( Vec1.Vecz, 2 ) ) );
	Mag2 = sqrt ( ( pow( Vec2.Vecx, 2 ) ) + ( pow ( Vec2.Vecy, 2 ) ) + ( pow ( Vec2.Vecz, 2 ) ) );

	angle = acos(scalar / (Mag1 * Mag2));
	angle = angle * (180 / 3.1415926535897);

	return angle;
}

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

float Vector4::Dot_Product ( Vector4 Vec1, Vector4 Vec2 )
{
	float ScalarResult;

	ScalarResult = ( Vec1.Vecx * Vec2.Vecx ) + ( Vec1.Vecy * Vec2.Vecy ) + ( Vec1.Vecz * Vec2.Vecz );

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


//---------------MATRIX---------------\\


Matrix4x4 Matrix4x4::Matrix_Matrix_Addition( Matrix4x4 Mat1, Matrix4x4 Mat2 )
{
	Matrix4x4 MatrixResult;

	for( int c = 0; c < 4; c++ )
	{
		for( int r = 0; r < 4; r ++ )
		{
			MatrixResult.Matrix[r][c] = Mat1.Matrix[r][c] + Mat2.Matrix[r][c];
		}
	}

	return MatrixResult;
}

Matrix4x4 Matrix4x4::Matrix_Matrix_Subtraction( Matrix4x4 Mat1, Matrix4x4 Mat2 )
{
	Matrix4x4 MatrixResult;

	for( int c = 0; c < 4; c++ )
	{
		for( int r = 0; r < 4; r ++ )
		{
			MatrixResult.Matrix[r][c] = Mat1.Matrix[r][c] - Mat2.Matrix[r][c];
		}
	}

	return MatrixResult;
}

Matrix4x4 Matrix4x4::Matrix_Matrix_Multiplication( Matrix4x4 Mat1, Matrix4x4 Mat2 )
{
	Matrix4x4 MatrixResult;
	int counter = 0;
	int counter2 = 0;

	for( int c = 0; c < 4; c++ )
	{
		for( int r = 0; r < 4; r ++ )
		{
			MatrixResult.Matrix[c][r] = (Mat1.Matrix[c][counter] * Mat2.Matrix[counter2][r]) + (Mat1.Matrix[c][counter + 1] * Mat2.Matrix[counter2 + 1][r]) + (Mat1.Matrix[c][counter + 2] * Mat2.Matrix[counter2 + 2][r]) + (Mat1.Matrix[c][counter + 3] * Mat2.Matrix[counter2 + 3][r]);
		}
		counter = 0;
		counter2 = 0;
	}


	return MatrixResult;
}

Matrix4x4 Matrix4x4::Matrix_Vector_Multiplication( Matrix4x4 Mat, Vector4 Vec )
{
	Matrix4x4 MatrixResult;
	float x;
	float y;
	float z;
	float w;

	x = Vec.Get_Vecx();
	y = Vec.Get_Vecy();
	z = Vec.Get_Vecz();
	w = Vec.Get_Vecw();

	for( int c = 0; c < 4; c++ )
	{
		for( int r = 0; r < 4; r ++ )
		{
			if ( c == 0 )
			{
				MatrixResult.Matrix[r][c] = Mat.Matrix[r][c] * x;
			}
			if ( c == 1 )
			{
				MatrixResult.Matrix[r][c] = Mat.Matrix[r][c] * y;
			}
			if ( c == 2 )
			{
				MatrixResult.Matrix[r][c] = Mat.Matrix[r][c] * z;
			} 
			if ( c == 3 )
			{
				MatrixResult.Matrix[r][c] = Mat.Matrix[r][c] * w;
			}

		}
	}

	return MatrixResult;
}

Matrix4x4 Matrix4x4::Matrix_Scalar_Multiplication( Matrix4x4 Mat, int Num )
{
	Matrix4x4 MatrixResult;

	for( int c = 0; c < 4; c++ )
	{
		for( int r = 0; r < 4; r ++ )
		{
			MatrixResult.Matrix[r][c] = Mat.Matrix[r][c] * Num;
		}
	}

	return MatrixResult;
}

Matrix4x4 Matrix4x4::Matrix_Scalar_Division( Matrix4x4 Mat, int Num )
{
	Matrix4x4 MatrixResult;

	for( int c = 0; c < 4; c++ )
	{
		for( int r = 0; r < 4; r ++ )
		{
			MatrixResult.Matrix[r][c] = Mat.Matrix[r][c] / Num;
		}
	}

	return MatrixResult;
}

#endif //_MATHFUNCITONS_H_