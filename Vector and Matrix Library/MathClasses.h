#ifndef _MATHCLASSES_H_
#define _MATHCLASSES_H_


//---------------VECTOR---------------\\



//Vector4 Class
typedef class Vector4
{
public:

	void Set_Vecx(float);
	void Set_Vecy(float);
	void Set_Vecz(float);
	void Set_Vecw(float);
	void Set_angle(float);
	float Get_Vecx( void ) const;
	float Get_Vecy( void ) const;
	float Get_Vecz( void ) const;
	float Get_Vecw( void ) const;
	float Get_angle( void ) const;

	Vector4 Vector_Vector_Addition( Vector4, Vector4 );
	Vector4 Vector_Vector_Subtraction( Vector4, Vector4 );
	Vector4 Vector_Scalar_Multiplication( Vector4, float );
	Vector4 Vector_Scalar_Division( Vector4, float );
	float Dot_Product (Vector4, Vector4);
	Vector4 Cross_Product ( Vector4, Vector4 );
	float Vector_Angle ( Vector4, Vector4 );

private:

	float Vecx;
	float Vecy;
	float Vecz;
	float Vecw;
	float angle;

}Vector4;

//Vector4 Functions
void Vector4::Set_Vecx(float x)
{
	Vecx = x;
}
float Vector4::Get_Vecx() const
{
	return Vecx;
}

void Vector4::Set_Vecy(float y)
{
	Vecy = y;
}
float Vector4::Get_Vecy() const
{
	return Vecy;
}

void Vector4::Set_Vecz(float z)
{
	Vecz = z;
}
float Vector4::Get_Vecz() const
{
	return Vecz;
}

void Vector4::Set_Vecw(float w)
{
	Vecw = w;
}
float Vector4::Get_Vecw() const
{
	return Vecw;
}

void Vector4::Set_angle(float a)
{
	angle = a;
}
float Vector4::Get_angle() const
{
	return angle;
}



//---------------MATRIX---------------\\



//Matrix4x4 Class
typedef class Matrix4x4
{
public:

	void Set_MatrixValue( float, int, int );
	float Get_MatrixValue( int, int ) const;
	Matrix4x4 Matrix_Matrix_Addition( Matrix4x4, Matrix4x4 );
	Matrix4x4 Matrix_Matrix_Subtraction( Matrix4x4, Matrix4x4 );
	Matrix4x4 Matrix_Matrix_Multiplication( Matrix4x4, Matrix4x4 );
	Matrix4x4 Matrix_Vector_Multiplication( Matrix4x4, Vector4 );
	Matrix4x4 Matrix_Scalar_Multiplication( Matrix4x4, int );
	Matrix4x4 Matrix_Scalar_Division( Matrix4x4, int );

private:

	float Matrix[4][4];

}Matrix4x4;

//Matrix4x4 Functions
void Matrix4x4::Set_MatrixValue( float num, int pointerR, int pointerC )
{
	Matrix[pointerR][pointerC] = num;
}
float Matrix4x4::Get_MatrixValue( int pointerR, int pointerC ) const
{
	return Matrix[pointerR][pointerC];
}

#endif // _MATHCLASSES_H_