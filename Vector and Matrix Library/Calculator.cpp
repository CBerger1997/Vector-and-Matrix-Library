#include <iostream>
#include "MathFunctions.h"
#include "MainFunctions.h" 
//struct containing the main maths vectors
struct MathsVars
{
	Vector4 Vector_1;
	Vector4 Vector_2;
	Matrix4x4 Matrix1;
	Matrix4x4 Matrix2;
}Maths;

int main( void )
{
	//main variables
	bool m_VecInput = false;
	bool m_MatInput = false;
	int m_MenuAns;

	//loop allowing user to enter options for a menu until they enter (5) for exit
	do
	{
		system("CLS");
		std::cout << "------------------------------" << std::endl;
		std::cout << "-                            -" << std::endl;
		std::cout << "-VECTOR AND MATRIX CALCULATOR-" << std::endl;
		std::cout << "-                            -" << std::endl;
		std::cout << "------------------------------" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "Please select an option:" << std::endl;
		std::cout << "(1) Input Vector" << std::endl;
		std::cout << "(2) Input Matrix" << std::endl;
		//checks to see if user has input vectors
		if ( m_VecInput == true )
		{
			std::cout << "(3) Vector Maths" << std::endl;
		}
		//checks to see if user has input Matrices
		if ( m_MatInput == true )
		{
			std::cout << "(4) Matrix Maths" << std::endl;
		}

		std::cout << "(5) Exit" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "Answer: ";
		std::cin >> m_MenuAns;

		switch ( m_MenuAns )
		{
		case 1:
			//take user to InputVector function
			InputVector();
			m_VecInput = true;
			break;

		case 2:
			//take user to InputMatrix function
			InputMatrix();
			m_MatInput = true;
			break;
		case 3:
			//take user to VectorMaths function
			VectorMaths();
			break;
		case 4:
			//take user to MatrixMaths function
			MatrixMaths( m_VecInput );
			break;
		case 5:

			break;
		default:
			//produces error on incorrect input by user
			if ( m_MenuAns < 0 || m_MenuAns > 5 )
			{
				std::cout << "------------ERROR------------" << std::endl;
				std::cout << "-Please enter a valid option-" << std::endl;
				std::cout << "-----------------------------" << std::endl;
				std::cin.get();
				std::cin.get();
			}
			break;
		}
		//breaks loop when user enters 5
	}while ( m_MenuAns != 5);
}

void InputVector ( void )
{
	//inputVector Variables
	float m_x;
	float m_y;
	float m_z;
	float m_w = 1.0f;

	//loop allowing user to input x, y and z components of a vector
	for ( int i = 1; i < 3; i++ )
	{
		std::cout << "Input the x component for Vector " << i << std::endl;
		std::cin >> m_x;
		std::cout << "Input the y component for Vector " << i << std::endl;
		std::cin >> m_y;
		std::cout << "Input the z component for Vector " << i << std::endl;
		std::cin >> m_z;
		//checks to see if user is inputting values for Vector_1
		if( i == 1 )
		{
			Maths.Vector_1.Set_Vecx(m_x);
			Maths.Vector_1.Set_Vecy(m_y);
			Maths.Vector_1.Set_Vecz(m_z);
			Maths.Vector_1.Set_Vecw(m_w);
		}
		//checks to see if user is inputting values for Vector_2
		if( i == 2 )
		{
			Maths.Vector_2.Set_Vecx(m_x);
			Maths.Vector_2.Set_Vecy(m_y);
			Maths.Vector_2.Set_Vecz(m_z);
			Maths.Vector_2.Set_Vecw(m_w);
		}

	}
}

void InputMatrix ( void )
{
	//InputMatrix Variables
	int m_value[16];
	int m_counter = 1;

	//produces diagram of matrix inputs
	std::cout << "MATRIX DIAGRAM" << std::endl;
	std::cout << "|[1][4][7][10]|" << std::endl;
	std::cout << "|[2][5][8][11]|" << std::endl;
	std::cout << "|[3][6][9][12]|" << std::endl;
	std::cout << "|[w][w][w][w]|" << std::endl;
	std::cout << "" << std::endl;

	//loop to allow user to input values for Matrix1
	for( int m_c = 0; m_c < 4; m_c++ )
	{
		for( int m_r = 0; m_r < 4; m_r ++ )
		{
			if( m_r == 3 )
			{
				Maths.Matrix1.Set_MatrixValue( 1, m_r, m_c );
			}
			else
			{
				std::cout << "Enter component " << ( m_counter ) << " for the matrix 1: ";
				std::cin >> m_value[ m_r + m_c ];
				Maths.Matrix1.Set_MatrixValue( m_value[ m_r + m_c ], m_r, m_c );
				m_counter ++;
			}
		}
		std::cout << std::endl;
	}

	std::cout << " " << std::endl;

	m_counter = 1;

	//loop to allow user to input values for Matrix2
	for( int m_c = 0; m_c < 4; m_c++ )
	{
		for( int m_r = 0; m_r < 4; m_r ++ )
		{
			if( m_r == 3 )
			{
				Maths.Matrix2.Set_MatrixValue( 1, m_r, m_c );
			}
			else
			{
				std::cout << "Enter component " << ( m_counter ) << " for the matrix 2: ";
				std::cin >> m_value[ m_r + m_c ];
				Maths.Matrix2.Set_MatrixValue( m_value[ m_r + m_c ], m_r, m_c );
				m_counter ++;
			}
		}
		std::cout << std::endl;
	}
}

void VectorMaths ( void )
{
	//VectorMaths variables
	int m_MenuAns;

	//loop allowing user to enter options for a menu until they enter (8) for exit
	do
	{
		system("CLS");
		std::cout << "--------------" << std::endl;
		std::cout << "-VECTOR MATHS-" << std::endl;
		std::cout << "--------------" << std::endl;

		std::cout << "Please select an option:" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "-Vector and Scalar-" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "(1) Multiplication" << std::endl;
		std::cout << "(2) Division" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "-Vector and Vector-" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "(3) Addition" << std::endl;
		std::cout << "(4) Subtraction" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "-Other-" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "(5) Dot Product" << std::endl;
		std::cout << "(6) Cross Product" << std::endl;
		std::cout << "(7) Vector Angle" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "(8) Back" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "Answer: ";
		std::cin >> m_MenuAns;

		switch (m_MenuAns)
		{
		case 1:
			//take user to VectorAndScalar function
			VectorAndScalar( m_MenuAns );
			break;
		case 2:
			//take user to VectorAndScalar function
			VectorAndScalar( m_MenuAns );
			break;
		case 3:
			//take user to VectorAndVector function
			VectorAndVector( m_MenuAns );
			break;
		case 4:
			//take user to VectorAndVector function
			VectorAndVector( m_MenuAns );
			break;
		case 5:
			//take user to VectorOther function
			VectorOther( m_MenuAns );
			break;
		case 6:
			//take user to VectorOther function
			VectorOther( m_MenuAns );
			break;
		case 7:
			//take user to VectorOther function
			VectorOther( m_MenuAns );
			break;
		case 8:

			break;
		default:
			//produces error on incorrect input by user
			if (m_MenuAns < 0 || m_MenuAns > 8)
			{
				std::cout << "------------ERROR------------" << std::endl;
				std::cout << "-Please enter a valid option-" << std::endl;
				std::cout << "-----------------------------" << std::endl;
				std::cin.get();
				std::cin.get();
			}
			break;
		}
		//breaks loop when user enters 8
	}while ( m_MenuAns != 8 );

}

void VectorAndScalar ( int m_Menu )
{
	system("CLS");

	//VectorAndScalar Variables
	Vector4 m_VecResult;
	float m_Scalar;
	int m_ans;


	//-------------Multiplication-------------

	//checks whether user input menu option for Multiplication
	if ( m_Menu == 1 )
	{
		//loops until user gives valid answer
		do
		{
			//asks user for which vector to use
			std::cout << "Are you using (1) Vector1 or (2) Vector2: ";
			std::cin >> m_ans;
		}while ( m_ans != 1 && m_ans != 2 );
		//asks user for scalar input
		std::cout << "Enter the Scalar you wish to multiply the vector by: ";
		std::cin >> m_Scalar;
		//produces value basied on vector and scalar input
		if (m_ans == 1 )
		{
			m_VecResult = m_VecResult.Vector_Scalar_Multiplication ( Maths.Vector_1, m_Scalar );
		}
		if (m_ans== 2 )
		{
			m_VecResult = m_VecResult.Vector_Scalar_Multiplication ( Maths.Vector_2, m_Scalar );
		}
	}


	//-------------Division-------------

	//checks whether user input menu option for Division
	if ( m_Menu == 2 )
	{
		//loops until user gives valid answer
		do
		{
			//asks user for which vector to use
			std::cout << "Are you using (1) Vector1 or (2) Vector2: ";
			std::cin >> m_ans;
		}while (m_ans!= 1 &&m_ans!= 2 );
		//asks user for scalar input
		std::cout << "Enter the Scalar you wish to divide the vector by: ";
		std::cin >> m_Scalar;
		//produces value basied on vector and scalar input
		if (m_ans== 1 )
		{
			m_VecResult = m_VecResult.Vector_Scalar_Division( Maths.Vector_1, m_Scalar );
		}
		if (m_ans== 2 )
		{
			m_VecResult = m_VecResult.Vector_Scalar_Division( Maths.Vector_2, m_Scalar );
		}
	}
	//outputs results of vector and scalar
	std::cout << m_VecResult.Get_Vecx() << " x, ";
	std::cout << m_VecResult.Get_Vecy() << " y, ";
	std::cout << m_VecResult.Get_Vecz() << " z, ";
	std::cout << m_VecResult.Get_Vecw() << " w " << std::endl;
	std::cin.get();
	std::cin.get();

}

void VectorAndVector ( int m_Menu )
{
	system("CLS");

	//VectorAndVector Variable
	Vector4 m_VecResult;



	//-------------Addition-------------

	//checks whether user input menu option for Addition
	if ( m_Menu == 3 )
	{
		m_VecResult = m_VecResult.Vector_Vector_Addition(Maths.Vector_1, Maths.Vector_2);
	}


	//-------------Subtraction-------------

	//checks whether user input menu option for Subtraction
	if ( m_Menu == 4 )
	{
		m_VecResult = m_VecResult.Vector_Vector_Subtraction(Maths.Vector_1, Maths.Vector_2);
	}
	//outputs Vector result
	std::cout << m_VecResult.Get_Vecx() << " x, ";
	std::cout << m_VecResult.Get_Vecy() << " y, ";
	std::cout << m_VecResult.Get_Vecz() << " z, ";
	std::cout << m_VecResult.Get_Vecw() << " w " << std::endl;
	std::cin.get();
	std::cin.get();
}

void VectorOther ( int m_Menu )
{
	system("CLS");
	Vector4 m_VecResult;
	int m_Scalar;



	//-------------Dot Product-------------

	//checks whether user input menu option for Dot Product
	if ( m_Menu == 5 )
	{
		m_Scalar = m_VecResult.Dot_Product( Maths.Vector_1, Maths.Vector_2 );
		//outputs Scalar result
		std::cout << m_Scalar << std::endl;
	}


	//-------------Cross Product-------------

	//checks whether user input menu option for Cross Product
	if ( m_Menu == 6 )
	{
		m_VecResult = m_VecResult.Cross_Product(Maths.Vector_1, Maths.Vector_2);

		//outputs Vector result
		std::cout << m_VecResult.Get_Vecx() << " x, ";
		std::cout << m_VecResult.Get_Vecy() << " y, ";
		std::cout << m_VecResult.Get_Vecz() << " z, ";
		std::cout << m_VecResult.Get_Vecw() << " w " << std::endl;
	}


	//-------------Vector Angle-------------


	//checks whether user input menu option for Vector Angle
	if ( m_Menu == 7 )
	{
		float angle;
		angle = Maths.Vector_1.Vector_Angle ( Maths.Vector_1, Maths.Vector_2 );
		//outputs Angle
		std::cout << angle << std::endl;
	}

	std::cin.get();
	std::cin.get();

}

void MatrixMaths ( bool m_VecInput )
{
	//MatrixMaths variables
	int m_MenuAns;

	//loop allowing user to enter options for a menu until they enter (8) for exit
	do
	{
		system("CLS");
		std::cout << "--------------" << std::endl;
		std::cout << "-MATRIX MATHS-" << std::endl;
		std::cout << "--------------" << std::endl;

		std::cout << "Please select an option:" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "-Matrix and Scalar-" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "(1) Multiplication" << std::endl;
		std::cout << "(2) Division" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "-Matrix and Vector-" << std::endl;
		std::cout << "" << std::endl;

		//checks to see if the user has also input vectors
		if ( m_VecInput == true )
		{
			std::cout << "(3) Multiplication" << std::endl;
			std::cout << "" << std::endl;
		}

		std::cout << "-Matrix and Matrix-" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "(4) Addition" << std::endl;
		std::cout << "(5) Subtraction" << std::endl;
		std::cout << "(6) Multiplication" << std::endl;
		std::cout << "" << std::endl;

		std::cout << "(7) Back" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "Answer: ";
		std::cin >> m_MenuAns;

		switch (m_MenuAns)
		{
		case 1:
			//take user to MatrixAndScalar function
			MatrixAndScalar( m_MenuAns );
			break;

		case 2:
			//take user to MatrixAndScalar function
			MatrixAndScalar( m_MenuAns );
			break;
		case 3:
			//take user to MatrixAndVector function
			MatrixAndVector();
			break;
		case 4:
			//take user to MatrixAndMatrix function
			MatrixAndMatrix( m_MenuAns );
			break;
		case 5:
			//take user to MatrixAndMatrix function
			MatrixAndMatrix( m_MenuAns );
			break;
		case 6:
			//take user to MatrixAndMatrix function
			MatrixAndMatrix( m_MenuAns );
			break;
		case 7:

			break;
		default:
			//produce error on  inccorect user input
			if (m_MenuAns < 0 || m_MenuAns > 7)
			{
				std::cout << "------------ERROR------------" << std::endl;
				std::cout << "-Please enter a valid option-" << std::endl;
				std::cout << "-----------------------------" << std::endl;
				std::cin.get();
				std::cin.get();
			}
			break;
		}
		//breaks loop when user enters 7
	}while ( m_MenuAns != 7 );
}

void MatrixAndScalar ( int m_Menu )
{
	system("CLS");
	//MatrixAndScalar Variables
	Matrix4x4 m_MatResult;
	float m_Scalar;
	int m_ans;


	//-------------Multiplication-------------

	//checks whether user input menu option for Multiplication
	if ( m_Menu == 1 )
	{
		//loops until user gives valid answer
		do
		{
			//asks user for which Matrix to use
			std::cout << "Are you using (1) Matrix1 or (2) Matrix2: ";
			std::cin >> m_ans;
		}while (m_ans!= 1 &&m_ans!= 2 );
		//asks user for Scalar input
		std::cout << "Enter the Scalar you wish to multiply the Matrix by: ";
		std::cin >> m_Scalar;
		//produces Matrix value dependent on what user chose
		if (m_ans== 1 )
		{
			m_MatResult = m_MatResult.Matrix_Scalar_Multiplication( Maths.Matrix1, m_Scalar );
		}
		if (m_ans== 2 )
		{
			m_MatResult = m_MatResult.Matrix_Scalar_Multiplication( Maths.Matrix2, m_Scalar );
		}
	}


	//-------------Division-------------

	//checks whether user input menu option for Division
	if ( m_Menu == 2 )
	{
		do
		{
			//asks user for which Matrix to use
			std::cout << "Are you using (1) Matrix1 or (2) Matrix2: ";
			std::cin >> m_ans;
		}while (m_ans!= 1 &&m_ans!= 2 );
		//asks user for Scalar input
		std::cout << "Enter the Scalar you wish to divide the vector by: ";
		std::cin >> m_Scalar;
		//produces Matrix value dependent on what user chose
		if (m_ans== 1 )
		{
			m_MatResult = m_MatResult.Matrix_Scalar_Division( Maths.Matrix1, m_Scalar );
		}
		if (m_ans== 2 )
		{
			m_MatResult = m_MatResult.Matrix_Scalar_Division( Maths.Matrix2, m_Scalar );
		}
	}

	//outputs Matrix Result
	for( int m_r = 0; m_r < 4; m_r++ )
	{
		for( int m_c = 0; m_c < 4; m_c ++ )
		{
			std::cout << m_MatResult.Get_MatrixValue( m_r, m_c ) << " ";
		}
		std::cout << std::endl;
	}
	std::cin.get();
	std::cin.get();

}

void MatrixAndVector ()
{
	system("CLS");
	Matrix4x4 m_MatResult;
	int m_MatAns;
	int m_VecAns;

	//loops until user gives valid answer
	do
	{
		//asks user for which Matrix to use
		std::cout << "Are you using (1) Matrix1 or (2) Matrix2: ";
		std::cin >> m_MatAns;
	}while ( m_MatAns != 1 && m_MatAns != 2 );

	//loops until user gives valid answer
	do
	{
		//asks user for which vector to use
		std::cout << "Are you using (1) Vector1 or (2) Vector2: ";
		std::cin >> m_VecAns;
	}while ( m_VecAns != 1 && m_VecAns != 2 );

	//produces Matrix value dependent on user choices
	if ( m_MatAns == 1 && m_VecAns == 1 )
	{
		m_MatResult = m_MatResult.Matrix_Vector_Multiplication( Maths.Matrix1, Maths.Vector_1 );
	}
	if ( m_MatAns == 1 && m_VecAns == 2 )
	{
		m_MatResult = m_MatResult.Matrix_Vector_Multiplication( Maths.Matrix1, Maths.Vector_2 );
	}
	if ( m_MatAns == 2 && m_VecAns == 1 )
	{
		m_MatResult = m_MatResult.Matrix_Vector_Multiplication( Maths.Matrix2, Maths.Vector_1 );
	}
	if ( m_MatAns == 2 && m_VecAns == 2 )
	{
		m_MatResult = m_MatResult.Matrix_Vector_Multiplication( Maths.Matrix2, Maths.Vector_2 );
	}

	//outputs matrix result
	for( int m_r = 0; m_r < 4; m_r++ )
	{
		for( int m_c = 0; m_c < 4; m_c ++ )
		{
			std::cout << m_MatResult.Get_MatrixValue( m_r, m_c ) << " ";
		}
		std::cout << std::endl;
	}
	std::cin.get();
	std::cin.get();
}

void MatrixAndMatrix ( int m_Menu )
{
	system("CLS");
	Matrix4x4 m_MatResult;


	//-------------Addition-------------

	//checks whether user input menu option for Addition
	if ( m_Menu == 4 )
	{
		m_MatResult = m_MatResult.Matrix_Matrix_Addition( Maths.Matrix1, Maths.Matrix2 );
	}


	//-------------Subtraction-------------

	//checks whether user input menu option for Subtraction
	if ( m_Menu == 5 )
	{
		m_MatResult = m_MatResult.Matrix_Matrix_Subtraction( Maths.Matrix1, Maths.Matrix2 );
	}


	//-------------Multiplication-------------

	//checks whether user input menu option for Multiplication
	if ( m_Menu == 6 )
	{
		m_MatResult = m_MatResult.Matrix_Matrix_Multiplication( Maths.Matrix1, Maths.Matrix2 );
	}

	//outputs matrix result
	for( int m_r = 0; m_r < 4; m_r++ )
	{
		for( int m_c = 0; m_c < 4; m_c ++ )
		{
			std::cout << m_MatResult.Get_MatrixValue( m_r, m_c ) << " ";
		}
		std::cout << std::endl;
	}
	std::cin.get();
	std::cin.get();
}