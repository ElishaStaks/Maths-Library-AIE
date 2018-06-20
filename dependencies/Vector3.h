#pragma once
class Vector3
{
public:
	// union
	union
	{
		// struct which holds the x, y and z axis for vec3
		struct
		{
			float m_x, m_y, m_z;
		};
		float m[3];
	};

	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();

	// creating the normal vec3 operations
	Vector3 operator + (const Vector3& other);
	Vector3 operator - (const Vector3& other);
	Vector3 operator * (float scalar);
	Vector3 operator / (float scalar);

	// Pre-sclae Addition:  scalar + Vector2
	friend Vector3 operator + (float scalar, const Vector3& other);
	// Pre-sclae Subtraction:  scalar - Vector2
	friend Vector3 operator - (float scalar, const Vector3& other);
	// Pre-sclae Multiplication:  scalar * Vector2
	friend Vector3 operator * (float scalar, const Vector3& other);
	// Pre-sclae Division:  scalar / Vector2
	friend Vector3 operator / (float scalar, const Vector3& other);

	// Equals operator
	bool operator == (const Vector3& other);
	// Not Equals operator
	bool operator != (const Vector3& other);
	// Greater than operator
	bool operator > (const Vector3& other);
	// Greater or Equals operator
	bool operator >= (const Vector3& other);
	// Less than operator
	bool operator < (const Vector3& other);
	// Less or Equals operator
	bool operator <= (const Vector3& other);

	// Finds the angle between a vector 3
	float angleBetween(const Vector3& a, const Vector3& b);

	// converts int to float
	// eg int a = 10, float b = 20.0f
	// a = (int)f
	explicit operator float* ();
	float operator [] (int index);

	// creating the assignment operator vec3 operations
	Vector3& operator += (const Vector3& other);
	Vector3& operator -= (const Vector3& other);
	Vector3& operator *= (float scalar);
	Vector3& operator /= (float scalar);

	// Normalise:  Turns vector into a unit vector
	void normalise();
	Vector3 normalised();
	// length of the vector function
	float magnitude()const;
	// Square root the magnitude function
	float magnitudeSqr()const;
	// The distance between the points of the vector function
	float distance(const Vector3& other) const;

	//							| A.x |		| B.x |
	//					A * B = | A.y |  *	| B.y |
	// Dot Product:				| A.z |		| B.z |
	float dot(const Vector3& other)const;

	//					  | (a.y * b.z) - (a.z * b.y) |
	//					= | (a.z * b.x) - (a.x * b.z) |
	// Cross Product:	  | (a.x * b.y) - (a.y * b.x) |
	Vector3 cross(const Vector3& other)const;
	static float dot(const Vector3& a, const Vector3& b);
};
