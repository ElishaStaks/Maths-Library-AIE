#pragma once
class Vector2
{
public:
	// union
	union
	{
		// struct which holds the x and y axis for vec2
		struct
		{
			float m_x, m_y;
		};
		// if the data index 0 is called it calls the x value
		float m[2];
	};

	Vector2();
	Vector2(float x, float y);
	~Vector2();

	// creating the operations for vec2
	Vector2 operator + (const Vector2& other) const;
	Vector2 operator - (const Vector2& other) const;
	Vector2 operator * (float scalar);
	Vector2 operator / (float scalar);

	// Pre-sclae Addition:  scalar + Vector2
	friend Vector2 operator + (float scalar, const Vector2& other);
	// Pre-sclae Subtraction:  scalar - Vector2
	friend Vector2 operator - (float scalar, const Vector2& other);
	// Pre-sclae Multiplication:  scalar * Vector2
	friend Vector2 operator * (float scalar, const Vector2& other);
	// Pre-sclae Division:  scalar / Vector2
	friend Vector2 operator / (float scalar, const Vector2& other);

	// creating the assignment operator vec2 operations
	Vector2& operator += (const Vector2& other);
	Vector2& operator -= (const Vector2& other);
	Vector2& operator *= (float scalar);
	Vector2& operator /= (float scalar);

	// Equals operator
	bool operator == (const Vector2& other);
	// Not Equals operator
	bool operator != (const Vector2& other);
	// Greater than operator
	bool operator >  (const Vector2& other);
	// Greater or Equals operator
	bool operator >= (const Vector2& other);
	// Less than operator
	bool operator < (const Vector2& other);
	// Less or Equals operator
	bool operator <= (Vector2& other);

	// sub script operator
	float operator [] (int index);
	// converts int to float
	// eg int a = 10, float b = 20.0f
	// a = (int)f
	explicit operator float* ();

	// Normalise:  Turns vector into a unit vector
	void normalise();
	// length of the vector function
	float magnitude()const;
	// Square root the magnitude function
	float magnitudeSqr()const;
	// The distance between the points of the vector function
	float distance(const Vector2& other) const;
	// dot function
	//					A * B = | A.x |  *	| B.x |
	// Dot Product:				| A.y |		| B.y |
	float dot(const Vector2& other)const;
	// cross function
	Vector2 cross(const Vector2& other)const;



};
