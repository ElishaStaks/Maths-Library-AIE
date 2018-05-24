#pragma once
#include "Vector3.h"
class Matrix3
{
public:

	union
	{
		struct
		{
			float m[9];
		};
	};

	Matrix3();
	Matrix3(float a_x, float a_y, float a_z,
		float b_x, float b_y, float b_z,
		float c_x, float c_y, float c_z);
	Matrix3(const Matrix3 & other);

	float operator [] (int index);
	explicit operator float* ();

	Matrix3 Identity();
	Matrix3 Transpose();
	Matrix3 operator *(const Matrix3& a_mat) const;
	Vector3 operator *(const Vector3& a_vec) const;

	~Matrix3();
};

