#pragma once
class Vector2
{
public:



	typedef float real; // in case doubles are needed at some point

	// Variables
	real x;
	real y;


	// Constructors
	Vector2();
	Vector2(real _x, real _y);
	Vector2(const Vector2& other);

	// Destructors
	~Vector2();


	// assignment operators
	Vector2 & operator+= (const Vector2& other);
	Vector2 & operator-= (const Vector2& other);
	Vector2 & operator= (const Vector2& other);
	Vector2 & operator*= (const real scalar);
	Vector2 & operator/= (const real scalar);

	//binary operators
	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator*(float scalar) const;
	Vector2 operator/(float scalar) const;

	// comparison operators
	bool operator==(const Vector2& other) const;
	bool operator!=(const Vector2& other) const;



	// functions
	void Scale(float scalar);
	void Normalize();

	real AngleBetween(const Vector2 & other) const;
	real Dot(const Vector2 & other) const;
	real SquareMagnitude() const;
	real Magnitude() const;

	Vector2 Normalized() const;
	Vector2 Perpendicular() const;

	static real Dot(const Vector2 & a, const Vector2 & b);

	// Utility
	static Vector2 Zero();
	static Vector2 One();


};

