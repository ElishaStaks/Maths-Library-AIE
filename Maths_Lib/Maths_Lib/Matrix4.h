#pragma once
#include "Vector4.h"
class Matrix4
{
public:
	//Creating a union 
	union
	{
		//With a struct of 4x4 matrix
		struct
		{
			float m[16];
		};
	};
	//Default constructor
	Matrix4();
	//Copy constructor that takes in the the positions of the 3x3 matrix
	Matrix4(float a_x, float a_y, float a_z, float a_w, 
		    float b_x, float b_y, float b_z, float b_w, 
		    float c_x, float c_y, float c_z, float c_w,
		    float d_x, float d_y, float d_z, float d_w);

	//Copy cfloat d_x, float d_y, float d_z, float d_w)onstructor that alows us to set the axis's
	Matrix4(const Matrix4 & other);
	//Float operator that allows us to return the index in the matrix
	float operator [] (int index);
	//This operator allows us to return the matrix itself
	explicit operator float* ();
	//sets the scale of the game object which takes in the vector3
	void setScaled(const Vector4& v);
	//scales the game object which takes in a vector3
	void scale(const Vector4& v);

	////////////////////////////////////////
	void setRotateX(float radians);
	void setRotateY(float radians);
	void setRotateZ(float radians);
	void setRotateW(float radians);
	

	void rotateX(float radians);
	void rotateY(float radians);
	void rotateZ(float radians);
	void rotateW(float radians);
	////////////////////////////////////////

	//Identitiy fucntion which can return the matrix3
	Matrix4 Identity();
	//Transpose function sets the 3x3 matrix 
	Matrix4 Transpose();
	//Multiplication operator which multiplies the matrix indexes at a const
	Matrix4 operator *(const Matrix4& a_mat) const;
	//Multiplication operator which multiplies the matrix with a vector
	Vector4 operator *(const Vector4& a_vec) const;
	//Deconstructor
	~Matrix4();
};

