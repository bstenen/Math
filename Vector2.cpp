#include "Vector2.h"
#include <math.h>


// constructors
Vector2::Vector2(real _x, real _y) : x(_x), y(_y)
{
}
Vector2::Vector2(const Vector2 & other) : x(other.x), y(other.y)
{
}
Vector2::Vector2() : x(0), y(0)
{
}

//destructors
Vector2::~Vector2()
{
}







// assignment operators
Vector2 & Vector2::operator+= (const Vector2& other)
{
	x += other.x;
	y += other.y;
	return *this;
}
Vector2 & Vector2::operator-= (const Vector2& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}
Vector2 & Vector2::operator= (const Vector2& other)
{
	x = other.x;
	y = other.y;
	return *this;
}
Vector2 & Vector2::operator*= (const real scalar)
{
	Scale(scalar);
	return *this;
}
Vector2 & Vector2::operator/= (const real scalar)
{
	if (scalar == 0) // error if 0
		Scale(0);
	else
	{
		Scale(real(1)/scalar);
	}
	return *this;
}

//binary operators
Vector2 Vector2::operator+(const Vector2& other) const
{
	Vector2 result = *this;
	result += other;
	return result;
}
Vector2 Vector2::operator-(const Vector2& other) const
{
	Vector2 result = *this;
	result -= other;
	return result;
}
Vector2 Vector2::operator*(float scalar) const
{
	Vector2 result = *this;
	result *= scalar;
	return result;
}
Vector2 Vector2::operator/(float scalar) const
{
	Vector2 result = *this;
	result /= scalar;
	return result;
}


// comparison operators
bool Vector2::operator==(const Vector2& other) const
{
	return (x == other.x && y == other.y); // floating point issues potentially
}
bool Vector2::operator!=(const Vector2& other) const
{
	return !(*this == other);
}

Vector2::real Vector2::AngleBetween(const Vector2 & other) const
{
	return static_cast<real>(acos(Dot(other)));
}

Vector2::real Vector2::Dot(const Vector2 & other) const
{
	return (x * other.x) + (y * other.y);
}

Vector2::real Vector2::Dot(const Vector2 & a, const Vector2 & b)
{
	return a.Dot(b);
}

void Vector2::Scale(float scalar)
{
	x *= scalar;
	y *= scalar;
}

Vector2::real Vector2::SquareMagnitude() const
{
	return (x * x) + (y * y);
}
Vector2::real Vector2::Magnitude() const
{
	return static_cast<real>(sqrt(SquareMagnitude()));
}
void Vector2::Normalize()
{
	real len = Magnitude();
	if (len != 0)		// can't normalize a zero vector
	{
		x = x / len;
		y = y / len;
	}
}
Vector2 Vector2::Normalized() const
{
	Vector2 result(*this);
	result.Normalize();
	return result;
}
Vector2 Vector2::Perpendicular() const
{
	return Vector2(-y, x);
}


Vector2 Vector2::Zero()
{
	return Vector2();
}
Vector2 Vector2::One()
{
	return Vector2(1, 1);
}
