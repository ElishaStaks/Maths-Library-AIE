#pragma once
class Vector2
{
public:

	union
	{
		//struct which holds the x and y axis for vec2
		struct
		{
			float m_x, m_y;
		};
	};

	Vector2();
	Vector2(float x, float y);

	//creating the operations for vec2
	Vector2 operator + (const Vector2& other);
	Vector2 operator - (const Vector2& other);
	Vector2 operator * (float scalar);
	Vector2 operator / (float scalar);

	friend Vector2 operator + (float scalar, const Vector2& other);
	friend Vector2 operator - (float scalar, const Vector2& other);
	friend Vector2 operator * (float scalar, const Vector2& other);
	friend Vector2 operator / (float scalar, const Vector2& other);

	//creating the operator and equal too vec3 operations
	Vector2 operator += (const Vector2& other);
	Vector2 operator -= (const Vector2& other);
	Vector2 operator *= (float scalar);
	Vector2 operator /= (float scalar);

	//scales the magnitude to length 1 function
	void normalise();
	//length of the vector function
	float magnitude()const;
	//Square root the magnitude function
	float magnitudeSqr()const;
	//The distance between the points of the vector function
	float distance(const Vector2& other) const;

	float dot(const Vector2& other)const;
	Vector2 cross(const Vector2& other)const;



	~Vector2();
};
