#pragma once
#include "Vector2.h"

class Matrix2
{
public:
	// Creating a union 
	union
	{
		// With a struct of 2x2 matrix
		struct
		{
			float m[4];
		};
	};
	// Default constructor
	Matrix2();
	// Copy constructor that takes in the positions of the 2x2 matrix
	Matrix2(float a_x, float a_y, float b_x,
		float b_y);

	// Copy constructor that allows us to set the axis's
	Matrix2(const Matrix2 & other);
	// Float operator that allows us to return the index in the matrix
	float operator [] (int index);
	// Float Pointer Cast:  Returns the array of floats
	explicit operator float* ();
	// Set Scale:  Creates a scaled matrix
	void setScaled(const Vector2& v);
	// Scale:  Times a matrix by a scaled matrix
	void scale(const Vector2& v);
	// sets rotation
	void setRotate(float radians);

	// Identitiy fucntion which can return the matrix2
	Matrix2 Identity();
	// Transpose:  Switches from Row-Major to Column-Major and vice versa
	Matrix2 Transpose();
	// Multiplication:  Matrix * Matrix
	Matrix2 operator *(const Matrix2& a_mat) const;
	// Multiplication operator which multiplies the matrix with a vector
	Vector2 operator *(const Vector2& a_vec) const;
	// Deconstructor
	~Matrix2();
};

