#include <iostream>
#include "Matrices.h"

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



	return MatrixResult;
}

Matrix4x4 Matrix4x4::Matrix_Vector_Multiplication( Matrix4x4 Mat, Vector4 Vec )
{
	Matrix4x4 MatrixResult;



	return MatrixResult;
}

Matrix4x4 Matrix4x4::Matrix_Scalar_Multiplication( Matrix4x4 Mat, int Num )
{
	Matrix4x4 MatrixResult;



	return MatrixResult;
}

Matrix4x4 Matrix4x4::Matrix_Scalar_Division( Matrix4x4 Mat, int Num )
{
	Matrix4x4 MatrixResult;



	return MatrixResult;
}