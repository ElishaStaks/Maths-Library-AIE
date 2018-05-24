#pragma once
#include "Vector2.h"

class Matrix2
{
public:
	union
	{
		struct
		{
			float m[4];
		};
	};

	Matrix2();
	Matrix2(float a_x, float a_y, float b_x,
		float b_y);
	Matrix2(const Matrix2 & other);

	float operator [] (int index);
	explicit operator float* ();

	Matrix2 Identity();
	Matrix2 Transpose();
	Matrix2 operator *(const Matrix2& a_mat) const;
	Vector2 operator *(const Vector2& a_vec) const;

	~Matrix2();
};

