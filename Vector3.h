#pragma once
class Vector3 
{
public:

	typedef float real; // in case doubles are needed at some point
	real x;
	real y;
	real z;

	Vector3();

	Vector3(real _x, real _y, real _z);

	Vector3(const Vector3 & copy);



	~Vector3();




	Vector3 & operator=(const Vector3 & other);
	Vector3 & operator+= (const Vector3 & other);
	Vector3 & operator-= (const Vector3 & other);
	Vector3 & operator*= (const real scalar);
	Vector3 & operator/= (const real scalar);

	Vector3 operator+(const Vector3 & other) const;
	Vector3 operator-(const Vector3 & other) const;
	Vector3 operator*(const real scalar) const;
	Vector3 operator/(const real scalar) const;

	bool operator==(const Vector3 & other) const;
	bool operator!=(const Vector3 & other) const;



	real Dot(const Vector3 & other) const;

	Vector3 Cross(const Vector3 & other) const;
	real AngleBetween(const Vector3 & other) const;

	void Scale(const real scalar);

	real SquareMagnitude() const;
	real Magnitude() const;

	void Normalize();
	Vector3 Normalized() const;

	static Vector3 Zero();
	static Vector3 One();


};

