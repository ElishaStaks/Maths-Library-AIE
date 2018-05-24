#include "Matrix3.h"



Matrix3::Matrix3()
{
	for (int i = 0; i < 9; i++)
	{
		m[i] = 0;
	}
}

Matrix3::Matrix3(float a_x, float a_y, float a_z, float b_x, float b_y, float b_z, float c_x, float c_y, float c_z)
{
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

float Matrix3::operator[](int index)
{
	return m[index];
}

Matrix3::operator float*()
{
	return m;
}

Matrix3 Matrix3::Identity()
{
	return Matrix3 (1.0f, 0.0f, 0.0f,
		           0.0f, 1.0f, 0.0f,
		           0.0f, 0.0f, 1.0f);
}

Matrix3 Matrix3::Transpose()
{
	return Matrix3(m[0], m[3], m[6],
		           m[1], m[4], m[7],
		           m[2], m[5], m[8]);
}

//====================== MATRIX MULTIPLICATION ========================//
//            | m[0] m[3] m[6] |      | a_m[0] a_m[3] a_m[6]                    step 1: Multiply the first matrix row by the whole second matrix
//            | m[1] m[4] m[7] |   *  | a_m[1] a_m[4] a_m[7]                    step 2: Multiply the second matrix row by the whole second matrix
//            | m[2] m[5] m[8] |      | a_m[2] a_m[5] a_m[8]                    step 3: Multiply the third matrix row by the whole second matrix
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

Vector3 Matrix3::operator*(const Vector3 & a_vec) const
{
	return Vector3(m[0],
	               m[1],
		           m[2]);
}


Matrix3::~Matrix3()
{
}
