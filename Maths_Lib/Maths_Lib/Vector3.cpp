#include "Vector3.h"
#include <math.h>



Vector3::Vector3()
{

}

//Constructor which takes in the x, y and z axis
Vector3::Vector3(float x, float y, float z) : m_x(x), m_y(y), m_z(z)
{

}

//Addition operator for vec3
Vector3 Vector3::operator+(const Vector3& other)
{
	return { m_x + other.m_x, m_y + other.m_y, m_z + other.m_z };
}

//Subtraction operator for vec3
Vector3 Vector3::operator-(const Vector3 & other)
{
	return { m_x - other.m_x, m_y - other.m_y, m_z - other.m_z };
}

//Addition and equal to operator for vec3
Vector3 Vector3::operator+=(const Vector3 & other)
{
	m_x + other.m_x, m_y + other.m_y, m_z + other.m_z;
	return *this;
}

//Subtraction and equal to operator for vec3
Vector3 Vector3::operator-=(const Vector3& other)
{
	m_x -= other.m_x, m_y -= other.m_y, m_z -= other.m_z;
	return *this;
}

//Multiplication and equal too operator for vec3
Vector3 Vector3::operator*=(float scalar)
{
	m_x *= scalar, m_y *= scalar, m_z *= scalar;
	return *this;
}

//Multiplication operator for vec3
Vector3 Vector3::operator*(float scalar)
{
	return { m_x * scalar, m_y * scalar, m_z * scalar };
}

//Division operator for vec3
Vector3 Vector3::operator/(float scalar)
{
	return { m_x / scalar, m_y / scalar, m_z / scalar };
}

//Division and equal to operator for vec3
Vector3 Vector3::operator/=(float scalar)
{
	m_x /= scalar, m_y /= scalar, m_z /= scalar;
	return *this;
}

//Making the vector a unit length of 1
//making the magnitude equal to 1
void Vector3::normalise()
{
	float mag = sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
	m_x /= mag, m_y /= mag, m_z /= mag;
}

Vector3 Vector3::normalised()
{
	float mag = sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
	return { m_x / mag, m_y / mag, m_z / mag };
}

//Returning the square rooted magnitude
float Vector3::magnitude() const
{
	{return sqrt(m_x * m_x + m_y * m_y + m_z * m_z); };
}

//Compares if the length of the vector is bigger than or less than some value
float Vector3::magnitudeSqr() const
{
	{return (m_x * m_x + m_y * m_y + m_z * m_z); };
}


//Checks the distance between the two points of the vector
//Then checks the magnitude of the vector
float Vector3::distance(const Vector3 & other) const
{
	float diffX = m_x - other.m_x;
	float diffY = m_y - other.m_y;
	float diffZ = m_z - other.m_z;
	return sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ);
}

float Vector3::dot(const Vector3 & other) const
{
	return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
}

Vector3 Vector3::cross(const Vector3 & other) const
{
	return { m_y * other.m_z - m_z * other.m_y, m_z * other.m_x - m_x * other.m_z, m_x * other.m_y - m_y * other.m_x };
}

Vector3::~Vector3()
{

}

