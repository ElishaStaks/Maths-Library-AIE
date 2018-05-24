#pragma once
#include "Vector3.h"
class Matrix3
{
public:
	//Creating a union 
	union
	{
		//With a struct of 3x3 matrix
		struct
		{
			float m[9];
		};
	};
	//Default constructor
	Matrix3();
	//Copy constructor that takes in the the positions of the 3x3 matrix
	Matrix3(float a_x, float a_y, float a_z, float b_x,
		float b_y, float b_z, float c_x, float c_y, float c_z);
	//Copy constructor that alows us to set the axis's
	Matrix3(const Matrix3 & other);
	//Float operator that allows us to return the index in the matrix
	float operator [] (int index);
	//This operator allows us to return the matrix itself
	explicit operator float* ();

	//////////////////////////////////////////////
	void setScaled(const Vector3& v);
	void scale(const Vector3& v);
	//////////////////////////////////////////////

	//Identitiy fucntion which can return the matrix3
	Matrix3 Identity();
	//Transpose function sets the 3x3 matrix 
	Matrix3 Transpose();
	//Multiplication operator which multiplies the matrix indexes at a const
	Matrix3 operator *(const Matrix3& a_mat) const;
	//Multiplication operator which multiplies the matrix with a vector
	Vector3 operator *(const Vector3& a_vec) const;
	//Deconstructor
	~Matrix3();
};

