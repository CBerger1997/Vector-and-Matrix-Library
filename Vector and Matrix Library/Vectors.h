//Vector4 Class
typedef class Vector4
{
public:

	void set_Vecx(float);
	void set_Vecy(float);
	void set_Vecz(float);
	void set_Vecw(float);
	float get_Vecx( void ) const;
	float get_Vecy( void ) const;
	float get_Vecz( void ) const;
	float get_Vecw( void ) const;

	Vector4 Vector_Vector_Addition( Vector4, Vector4 );
	Vector4 Vector_Vector_Subtraction( Vector4, Vector4 );
	Vector4 Vector_Scalar_Multiplication( Vector4, float );
	Vector4 Vector_Scalar_Division( Vector4, float );
	float Dot_Product (Vector4, Vector4, float);
	Vector4 Cross_Product ( Vector4, Vector4 );

private:

	float Vecx;
	float Vecy;
	float Vecz;
	float Vecw;

}Vector4;

//Vector4 Functions
void Vector4::set_Vecx(float x)
{
	Vecx = x;
}
float Vector4::get_Vecx() const
{
	return Vecx;
}

void Vector4::set_Vecy(float y)
{
	Vecy = y;
}
float Vector4::get_Vecy() const
{
	return Vecy;
}

void Vector4::set_Vecz(float z)
{
	Vecz = z;
}
float Vector4::get_Vecz() const
{
	return Vecz;
}

void Vector4::set_Vecw(float w)
{
	Vecw = w;
}
float Vector4::get_Vecw() const
{
	return Vecw;
}