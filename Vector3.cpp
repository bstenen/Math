#include "Vector3.h"

#include <math.h>

Vector3::Vector3() : x(0), y(0), z(0)
{
}

Vector3::Vector3(real _x, real _y, real _z) : x(_x), y(_y), z(_z)
{
}

Vector3::Vector3(const Vector3 & copy) : x(copy.x), y(copy.y), z(copy.z)
{
}


Vector3::~Vector3()
{
}


Vector3 & Vector3::operator=(const Vector3 & other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}
Vector3 & Vector3::operator+= (const Vector3 & other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}
Vector3 & Vector3::operator-= (const Vector3 & other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}
Vector3 & Vector3::operator*= (const real scalar)
{
	Scale(scalar);
	return *this;
}
Vector3 & Vector3::operator/= (const real scalar)
{
	if (scalar == 0)
		Scale(0);
	else
		Scale(real(1) / scalar);
	return *this;
}


Vector3 Vector3::operator+(const Vector3 & other) const
{
	Vector3 result(*this);
	result += other;
	return result;
}
Vector3 Vector3::operator-(const Vector3 & other) const
{
	Vector3 result(*this);
	result -= other;
	return result;
}
Vector3 Vector3::operator*(const real scalar) const
{
	Vector3 result(*this);
	result *= scalar;
	return result;
}
Vector3 Vector3::operator/(const real scalar) const
{
	Vector3 result(*this);
	result /= scalar;
	return result;
}


bool Vector3::operator==(const Vector3 & other) const
{
	return (x == other.x) && (y == other.y) && (z == other.z);
}
bool Vector3::operator!=(const Vector3 & other) const
{
	return !(*this == other);
}



Vector3::real Vector3::Dot(const Vector3 & other) const
{
	return (x * other.x) + (y * other.y) + (z * other.z);
}

Vector3 Vector3::Cross(const Vector3 & other) const
{
	Vector3 result;
	result.x = (y * other.z) - (z * other.y);
	result.y = (z * other.x) - (x * other.z);
	result.z = (x * other.y) - (y * other.x);
	return result;
}

Vector3::real Vector3::AngleBetween(const Vector3 & other) const
{
	real len1 = Magnitude();
	real len2 = other.Magnitude();

	return static_cast<real>(acos(Dot(other) / (len1 * len2)));
}

void Vector3::Scale(const real scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

Vector3::real Vector3::SquareMagnitude() const
{
	return (x * x) + (y * y) + (z * z);
}
Vector3::real Vector3::Magnitude() const
{
	return static_cast<real>(sqrt(SquareMagnitude()));
}

void Vector3::Normalize()
{
	real len = Magnitude();
	if (len != 0)		// can't normalize a zero vector
	{
		x /= len;
		y /= len;
		z /= len;
	}
}
Vector3 Vector3::Normalized() const
{
	Vector3 result(*this);
	result.Normalize();
	return result;
}

Vector3 Vector3::Zero()
{
	return Vector3(0, 0, 0);
}
Vector3 Vector3::One()
{
	return Vector3(1, 1, 1);
}