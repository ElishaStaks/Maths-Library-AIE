#pragma once
class Vector4
{
public:
	// union
	union
	{
		// struct which holds the x, y, z  and w axis for vec4
		struct
		{
			float m_x, m_y, m_z, m_w;
		};
		float m[4];
	};

	Vector4();
	// copy constructor
	Vector4(float x, float y, float z, float w);
	~Vector4();

	// creating the normal vec3 operations
	Vector4 operator + (const Vector4& other);
	Vector4 operator - (const Vector4& other);
	Vector4 operator * (float scalar);
	Vector4 operator / (float scalar);

	// Pre-sclae Addition:  scalar + Vector2
	friend Vector4 operator + (float scalar, const Vector4& other);
	// Pre-sclae Subtraction:  scalar - Vector2
	friend Vector4 operator - (float scalar, const Vector4& other);
	// Pre-sclae Multiplication:  scalar * Vector2
	friend Vector4 operator * (float scalar, const Vector4& other);
	// Pre-sclae Division:  scalar / Vector2
	friend Vector4 operator / (float scalar, const Vector4& other);

	// creating the assignment operator vec4 operations
	Vector4& operator += (const Vector4& other);
	Vector4& operator -= (const Vector4& other);
	Vector4& operator *= (float scalar);
	Vector4& operator /= (float scalar);

	// Equals operator
	bool operator == (const Vector4& other);
	// Not Equals operator
	bool operator != (const Vector4& other);
	// Greater than operator
	bool operator > (const Vector4& other);
	// Greater or Equals operator
	bool operator >= (const Vector4& other);
	// Less than operator
	bool operator < (const Vector4& other);
	// Less or Equals operator
	bool operator <= (const Vector4& other);

	// converts int to float
	// eg int a = 10, float b = 20.0f
	// a = (int)f
	explicit operator float* ();
	float operator [] (int index);

	// Normalise:  Turns vector into a unit vector
	void normalise();
	// length of the vector function
	float magnitude()const;
	// Square root the magnitude function
	float magnitudeSqr()const;
	// The distance between the points of the vector function
	float distance(const Vector4& other) const;

	//							| A.x |     | B.x |
	//							| A.y |	 *	| B.y |
	//					A * B = | A.z |  	| B.z |
	// Dot Product:				| A.w |		| B.w |
	float dot(const Vector4& other)const;

	//					  | (a.y * b.z) - (a.z * b.y) |
	//					  | (a.z * b.x) - (a.x * b.z) |
	//					= | (a.x * b.y) - (a.y * b.x) |
	// Cross Product:	  | 0 |
	Vector4 cross(const Vector4& other)const;

};

