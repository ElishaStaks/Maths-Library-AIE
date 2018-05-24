#include "Matrix2.h"



Matrix2::Matrix2()
{
	for (int i = 0; i < 4; i++)
	{
		m[i] = 0;
	}
}

Matrix2::Matrix2(float a_x, float a_y, float b_x, float b_y)
{
	m[0] = a_x;
	m[1] = a_y;
	m[2] = b_x;
	m[3] = b_y;


}

Matrix2::Matrix2(const Matrix2 & other)
{
	m[0] = other.m[0];
	m[1] = other.m[1];
	m[2] = other.m[2];
	m[3] = other.m[3];

}

float Matrix2::operator[](int index)
{
	return m[index];
}

Matrix2::operator float*()
{
	return m;
}

Matrix2 Matrix2::Identity()
{
	return Matrix2(1.0f, 0.0f,
		           0.0f, 1.0f,
		           0.0f, 0.0f);
}

Matrix2 Matrix2::Transpose()
{
	return Matrix2(m[0], m[3],
		           m[1], m[4],
		           m[2], m[5]);
}

//====================== MATRIX MULTIPLICATION ========================//
//            | m[0] m[3] m[6] |      | a_m[0] a_m[3] a_m[6]                    step 1: Multiply the first matrix row by the whole second matrix
//            | m[1] m[4] m[7] |   *  | a_m[1] a_m[4] a_m[7]                    step 2: Multiply the second matrix row by the whole second matrix
//            | m[2] m[5] m[8] |      | a_m[2] a_m[5] a_m[8]                    step 3: Multiply the third matrix row by the whole second matrix
Matrix2 Matrix2::operator*(const Matrix2 & a_mat) const
{
	return Matrix2(m[0] * a_mat.m[0] + m[1] * a_mat.m[2] + m[2] * a_mat.m[6],
		m[0] * a_mat.m[1] + m[1] * a_mat.m[4] + m[2] * a_mat.m[7],
		m[0] * a_mat.m[2] + m[1] * a_mat.m[5] + m[2] * a_mat.m[8],
		m[3] * a_mat.m[0] + m[4] * a_mat.m[3] + m[5] * a_mat.m[6],
);
}

Vector2 Matrix2::operator*(const Vector2 & a_vec) const
{
	return Vector2(m[0],
		           m[1]);
}


Matrix2::~Matrix2()
{
}

