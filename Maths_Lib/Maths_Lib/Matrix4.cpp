#include "Matrix4.h"
#include <math.h>


Matrix4::Matrix4()
{
	//Cycles through the 4x4 matrix and increments it
	for (int i = 0; i < 16; i++)
	{
		//Takes the matrix with index i which holds all the values in the 4x4 matrix such as 16
		m[i] = 0;
	}
}

//Sets the index values to each position
Matrix4::Matrix4(float a_x, float a_y, float a_z, float a_w, float b_x, float b_y, float b_z, float b_w, float c_x, float c_y, float c_z, float c_w,
	             float d_x, float d_y, float d_z, float d_w)
{
	//                                                                                                                      4x4
	//matrix index |0| = a_x     matrix index |1| = a_y    matrix index |2| = a_z     matrix index |3| = a_w          |  0  1  2  3  |
	//matrix index |4| = b_x     matrix index |5| = b_y    matrix index |6| = b_z     matrix index |7| = b_w          |  4  5  6  7  |
	//matrix index |8| = c_x     matrix index |9| = c_y    matrix index |10| = c_z    matrix index |11| = c_w         |  8  9  10 11 |
	//matrix index |12| = d_x    matrix index |13| = d_y   matrix index |14| = d_z    matrix index |15| = d_w         |  12 13 14 15 |

	m[0] = a_x;
	m[1] = a_y;
	m[2] = a_z;
	m[3] = a_w;
	m[4] = b_x;
	m[5] = b_y;
	m[6] = b_z;
	m[7] = b_w;
	m[8] = c_x;
	m[9] = c_y;
	m[10] = c_z;
	m[11] = c_w;
	m[12] = d_x;
	m[13] = d_y;
	m[14] = d_z;
	m[15] = d_w;
}

//Setting the axis's and the indexes to a constant type which will never change
//The axis's meaning the points of the matrix
Matrix4::Matrix4(const Matrix4 & other)
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
	m[9] = other.m[9];
	m[10] = other.m[10];
	m[11] = other.m[11];
	m[12] = other.m[12];
	m[13] = other.m[13];
	m[14] = other.m[14];
	m[15] = other.m[15];
}

//Returns the matrix's index
float Matrix4::operator[](int index)
{
	return m[index];
}

//Returns the matrix
Matrix4::operator float*()
{
	return m;
}

///////////////////////////////////////////////////////////////////////////// ROTATION /////////////////////////////////////////
//Sets the rotate for the X axis
void Matrix4::setRotateX(float radians)
{
	//leave X axis and elements unchanged                        //============== VISUAL REPRESENTATION =============//
	*this = { 1, 0, 0, 0,
			  0, cosf(radians), -sinf(radians), 0,               // | X  X  X  0 <------- Translation/ Transform
			  0, cosf(radians), cosf(radians), 0,                // | X  X  X  0 <------- Translation/ Transform
			  0, 0, 0, 1 };                                      // | X  X  X  0 <------- Translation/ Transform
}	                                                             // | 0  0  0  1 <------- Translation/ Transform                                                                //   ^  ^  ^  ^
                                                                 //  Bottom numbers all represent the translation of the 4th index 

//Sets the rotate for the Y axis
void Matrix4::setRotateY(float radians)
{
	*this = { cosf(radians), 0, -sinf(radians),
		      0, 1, 0,
		      sinf(radians), 0, cosf(radians) };
}
//Sets the rotate for the Z axis
void Matrix4::setRotateZ(float radians)
{
	*this = { cosf(radians), -sinf(radians), 0,
		      sinf(radians), cosf(radians), 0,
		      0, 0, 1 };
}
//Sets the rotate for the W axis
void Matrix4::setRotateW(float radians)
{
	*this = { 1, 0, 0,
		      0, cosf(radians), -sinf(radians),
		      0, cosf(radians), cosf(radians) };

}
//You add the value at which you would like to rotate the X axis in this function
void Matrix4::rotateX(float radians)
{
	Matrix4 m;
	m.setRotateX(radians);
	*this = *this * m;
}
//You add the value at which you would like to rotate the X axis in this function
void Matrix4::rotateY(float radians)
{
	Matrix4 m;
	m.setRotateY(radians);
	*this = *this * m;
}
//You add the value at which you would like to rotate the X axis in this function
void Matrix4::rotateZ(float radians)
{
	Matrix4 m;
	m.setRotateZ(radians);
	*this = *this * m;
}
//You add the value at which you would like to rotate the X axis in this function
void Matrix4::rotateW(float radians)
{
	Matrix4 m;
	m.setRotateW(radians);
	*this = *this * m;
}
/////////////////////////////////////////////////////////////////// ROTATION //////////////////////////////////////////////////////

//sets up an unrotated scaled matrix
void Matrix4::setScaled(const Vector4& v)
{
	//set scale of the axis
	*this = { v.m_x, 0, 0, 0,
			  0, v.m_y, 0, 0,
			  0, 0, v.m_z, 0,
			  0, 0, 0, v.m_w };
}

//where to set the value of how big you want the object to be
void Matrix4::scale(const Vector4 & v)
{
	Matrix4 m;
	m.setScaled(v);
	*this = *this * m;
}

//Identity matrix is a square matrix with main diagonal elements as 1 and the rest is 0
//This is a 4x4 identity matrix
Matrix4 Matrix4::Identity()
{
	return Matrix4(1.0f, 0.0f, 0.0f, 0.0f,
		           0.0f, 1.0f, 0.0f, 0.0f,
		           0.0f, 0.0f, 1.0f, 0.0f,
	               0.0f, 0.0f, 0.0f, 1.0f);
}

//This is the columns and rows of a 4x4 matrix 
Matrix4 Matrix4::Transpose()
{
	return Matrix4(m[0], m[4], m[8], m[12],
		           m[1], m[5], m[9], m[13],
		           m[2], m[6], m[10], m[14],
		           m[3], m[7], m[11], m[15]);
}

//============================== MATRIX MULTIPLICATION 4X4 =========================//
//            | m[0]  m[1]  m[2]  m[3]  |      | a_m[0]  a_m[1]  a_m[2]  a_m[3]  |            Step 1: Multiply the first matrix row by the whole second matrix on the right           // | 0x0 + 1x4 + 2x8 + 3x12 + 0x1 + 1x5 + 2x9 + 3x13 + 0x2 + 1x6 + 2x10 + 3x14 + 0x3 + 1x7 + 2x11 + 3x15                   | <--- first row   
//            | m[4]  m[5]  m[6]  m[7]  |  *   | a_m[4]  a_m[5]  a_m[6]  a_m[7]  |            Step 2: Multiply the second matrix row by the whole second matrix	on the right	      // | 4x0 + 5x4 + 6x8 + 7x12 + 4x1 + 5x5 + 6x9 + 3x13 + 4x2 + 5x6 + 6x10 + 3x14 + 4x3 + 5x7 + 6x11 + 3x15                   | <--- second row
//            | m[8]  m[9]  m[10] m[11] |      | a_m[8]  a_m[9]  a_m[10] a_m[11] |            Step 3: Multiply the third matrix row by the whole second matrix on the right           // | 8x0 + 9x4 + 10x8 + 11x12 + 8x1 + 9x5 + 10x9 + 11x13 + 8x2 + 9x6 + 10x10 + 11x14 + 8x3 + 9x7 + 10x11 + 11x15           | <--- third row
//            | m[12] m[13] m[14] m[15] |	   | a_m[12] a_m[13] a_m[14] a_m[15] |            Step 4: Multiply the fourth matrix row by the whole second matrix on the right          // | 12x0 + 13x4 + 14x8 + 15x12 + 12x1 + 13x5 + 14x9 + 15x13 + 12x2 + 13x6 + 14x10 + 15x14 + 12x3 + 13x7 + 14x11 + 15x15   | <--- fouth row
Matrix4 Matrix4::operator*(const Matrix4 & a_mat) const
{
	return Matrix4(m[0] * a_mat.m[0] + m[1] * a_mat.m[4] + m[2] * a_mat.m[8] + m[3] * a_mat.m[12],
		           m[0] * a_mat.m[1] + m[1] * a_mat.m[5] + m[2] * a_mat.m[9] + m[3] * a_mat.m[13],
		           m[0] * a_mat.m[2] + m[1] * a_mat.m[6] + m[2] * a_mat.m[10] + m[3] * a_mat.m[14],
		           m[0] * a_mat.m[3] + m[1] * a_mat.m[7] + m[2] * a_mat.m[11] + m[3] * a_mat.m[15],
		           m[4] * a_mat.m[0] + m[5] * a_mat.m[4] + m[6] * a_mat.m[8] + m[7] * a_mat.m[12],
		           m[4] * a_mat.m[1] + m[5] * a_mat.m[5] + m[6] * a_mat.m[9] + m[7] * a_mat.m[13],
		           m[4] * a_mat.m[2] + m[5] * a_mat.m[6] + m[6] * a_mat.m[10] + m[7] * a_mat.m[14],
		           m[4] * a_mat.m[3] + m[5] * a_mat.m[7] + m[6] * a_mat.m[11] + m[7] * a_mat.m[15],
		           m[8] * a_mat.m[0] + m[9] * a_mat.m[4] + m[10] * a_mat.m[8] + m[11] * a_mat.m[12],
		           m[8] * a_mat.m[1] + m[9] * a_mat.m[5] + m[10] * a_mat.m[9] + m[11] * a_mat.m[13],
		           m[8] * a_mat.m[2] + m[9] * a_mat.m[6] + m[10] * a_mat.m[10] + m[11] * a_mat.m[14],
		           m[8] * a_mat.m[3] + m[9] * a_mat.m[7] + m[10] * a_mat.m[11] + m[11] * a_mat.m[15],
		           m[12] * a_mat.m[0] + m[13] * a_mat.m[4] + m[14] * a_mat.m[8] + m[15] * a_mat.m[12],
		           m[12] * a_mat.m[1] + m[13] * a_mat.m[5] + m[14] * a_mat.m[9] + m[15] * a_mat.m[13],
		           m[12] * a_mat.m[2] + m[13] * a_mat.m[6] + m[14] * a_mat.m[10] + m[15] * a_mat.m[14],
		           m[12] * a_mat.m[3] + m[13] * a_mat.m[7] + m[14] * a_mat.m[11] + m[15] * a_mat.m[15]);
}

//Multiplying a matrix with a vector
Vector4 Matrix4::operator*(const Vector4 & a_vec) const
{
	return Vector4(m[0],
		           m[1],
		           m[2],
	               m[3]);
}

//deconstructor
Matrix4::~Matrix4()
{
}