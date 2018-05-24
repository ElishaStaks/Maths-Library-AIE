#include "Matrix3.h"
#include <math.h>s


Matrix3::Matrix3()
{
	//cycles through the 3x3 matrix and increments it
	for (int i = 0; i < 9; i++)
	{
		//takes the matrix with index i which holds all the values in the 3x3 matrix such as 9
		m[i] = 0;
	}
}

//sets the index values to each position
Matrix3::Matrix3(float a_x, float a_y, float a_z, float b_x, float b_y, float b_z, float c_x, float c_y, float c_z)
{
	//                                                                                       3x3
	//matrix index |0| = a_x     matrix index |1| = a_y    matrix index |2| = a_z         | 0  1  2 |
	//matrix index |3| = b_x     matrix index |4| = b_y    matrix index |5| = b_z         | 3  4  5 |
	//matrix index |6| = c_x     matrix index |7| = c_y    matrix index |8| = c_z         | 6  7  8 |

	m[0] = a_x;
	m[1] = a_y;
	m[2] = a_z;
	m[3] = b_x;
	m[4] = b_y;
	m[5] = b_z;
	m[6] = c_x;
	m[7] = c_y;
	m[8] = c_z;

}

//Setting the axis's and the indexes to a constant type which will never change
//The axis's meaning the points of the matrix
Matrix3::Matrix3(const Matrix3 & other)
{
	m[0] = other.m[0];
	m[1] = other.m[1];
	m[2] = other.m[2];
	m[3] = other.m[3];
	m[4] = other.m[4];
	m[5] = other.m[5];
	m[6] = other.m[6];
	m[7] = other.m[7];
	m[8] = other.m[8];

}

//Returns the matrix's index
float Matrix3::operator[](int index)
{
	return m[index];
}

//Returns the matrix
Matrix3::operator float*()
{
	return m;
}

//sets up an unrotated scaled matrix
void Matrix3::setScaled(const Vector3& v)
{
	//set scale of the axis
	*this = { v.m_x, 0, 0,
	          0, v.m_y, 0, 
	          0, 0, v.m_z };
}

//where to set the value of how big you want the object to be
void Matrix3::scale(const Vector3 & v)
{
	Matrix3 m;
	m.setScaled(v);
	*this = *this * m;
}

///////////////////////////////////////////////////////////////////////////// ROTATION /////////////////////////////////////////
//Sets the rotate for the X axis
void Matrix3::setRotateX(float radians)
{
	//leave X axis and elements unchanged
	*this = { 1, 0, 0,
	          0, cosf(radians), -sinf(radians),
	          0, cosf(radians), cosf(radians) };

}

//Sets the rotate for the Y axis
void Matrix3::setRotateY(float radians)
{
	*this = { cosf(radians), 0, -sinf(radians),
			  0, 1, 0,
			  sinf(radians), 0, cosf(radians) };
}

//Sets the rotate for the Z axis
void Matrix3::setRotateZ(float radians)
{
	*this = { cosf(radians), -sinf(radians), 0,
			  sinf(radians), cosf(radians), 0,
			  0, 0, 1 };
}

//You add the value at which you would like to rotate the X axis in this function
void Matrix3::rotateX(float radians)
{
	Matrix3 m;
	m.setRotateX(radians);
	*this = *this * m;
}

void Matrix3::rotateY(float radians)
{
	Matrix3 m;
	m.setRotateY(radians);
	*this = *this * m;
}

void Matrix3::rotateZ(float radians)
{
	Matrix3 m;
	m.setRotateZ(radians);
	*this = *this * m;
}
/////////////////////////////////////////////////////////////////// ROTATION //////////////////////////////////////////////////////

//Identity matrix is a square matrix with main diagonal elements as 1 and the rest is 0
//This is a 3x3 identity matrix
Matrix3 Matrix3::Identity()
{
	return Matrix3 (1.0f, 0.0f, 0.0f,
		            0.0f, 1.0f, 0.0f,
		            0.0f, 0.0f, 1.0f);
}

//This is the columns and rows of a 3x3 matrix 
Matrix3 Matrix3::Transpose()
{
	return Matrix3(m[0], m[3], m[6],
		           m[1], m[4], m[7],
		           m[2], m[5], m[8]);
}

//====================== MATRIX MULTIPLICATION 3X3 ========================//
//            | m[0] m[3] m[6] |      | a_m[0] a_m[3] a_m[6] |                   step 1: Multiply the first matrix row by the whole second matrix                // | 0x0 + 1x3 + 2x6 + 0x1 + 1x4 + 2x7 + 0x2 + 1x5 + 2x8 + | <--- first row   
//            | m[1] m[4] m[7] |   *  | a_m[1] a_m[4] a_m[7] |                   step 2: Multiply the second matrix row by the whole second matrix				 // | 3x0 + 4x4 + 5x6 + 3x1 + 4x4 + 5x7 + 3x2 + 4x5 + 5x8 + | <--- second row
//            | m[2] m[5] m[8] |      | a_m[2] a_m[5] a_m[8] |                   step 3: Multiply the third matrix row by the whole second matrix                // | 6x0 + 7x3 + 8x6 + 6x1 + 7x4 + 8x7 + 6x2 + 7x5 + 8x8   | <--- third row
Matrix3 Matrix3::operator*(const Matrix3 & a_mat) const
{
	return Matrix3(m[0] * a_mat.m[0] + m[1] * a_mat.m[3] + m[2] * a_mat.m[6],
		           m[0] * a_mat.m[1] + m[1] * a_mat.m[4] + m[2] * a_mat.m[7],
	               m[0] * a_mat.m[2] + m[1] * a_mat.m[5] + m[2] * a_mat.m[8], 
		           m[3] * a_mat.m[0] + m[4] * a_mat.m[3] + m[5] * a_mat.m[6],
	               m[3] * a_mat.m[1] + m[4] * a_mat.m[4] + m[5] * a_mat.m[7],
		           m[3] * a_mat.m[2] + m[4] * a_mat.m[5] + m[5] * a_mat.m[8],
	               m[6] * a_mat.m[0] + m[7] * a_mat.m[3] + m[8] * a_mat.m[6],
		           m[6] * a_mat.m[1] + m[7] * a_mat.m[4] + m[8] * a_mat.m[7],
	               m[6] * a_mat.m[2] + m[7] * a_mat.m[5] + m[8] * a_mat.m[8]);
}

//Multiplying a matrix with a vector
Vector3 Matrix3::operator*(const Vector3 & a_vec) const
{
	return Vector3(m[0],
	               m[1],
		           m[2]);
}

//deconstructor
Matrix3::~Matrix3()
{
}
