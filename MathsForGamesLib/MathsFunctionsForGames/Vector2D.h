#pragma once
#include "math.h"

#ifndef _VECTOR2D
#define _VECTOR2D

namespace mffg
{
	//Forward Declarations
	class Matrix2X2;

	//Vector class for 2D
	class Vector2D
	{
	public:

		float x, y;

		//Default constructor
		Vector2D();

		//Destructor
		~Vector2D();

		//Three point float constructor for vector2D
		Vector2D(float a, float b);

		//Return element from vector
		float& operator [](int i);

		//Return constant element from vector
		const float& operator [](int i) const;

		//Vector2D multiplication with scalar by *= operation
		Vector2D& operator *=(float s);

		//Vector2D division with scalar by /= operation
		Vector2D& operator /=(float s);

		//Vector2D to Vector 2D addition by += operation
		Vector2D& operator +=(const Vector2D& v);

		//Vector2D to Vector 2D subtraction by -= operation
		Vector2D& operator -=(const Vector2D& v);
	};

	//Vector2D with scalar multiplication 
	inline Vector2D operator *(const Vector2D& v, float s)
	{
		return Vector2D(v.x * s, v.y * s);
	}

	//Vector2D with scalar division
	inline Vector2D operator /(const Vector2D& v, float s)
	{
		s = 1.0f / s;
		return (Vector2D(v.x * s, v.y * s));
	}

	//Vector2D sign negative
	inline Vector2D operator -(const Vector2D& v)
	{
		return (Vector2D(-v.x, -v.y));
	}

	//Calculate Magnitude of Vector2D
	inline float Magnitude(const Vector2D& v)
	{
		return (sqrt(v.x * v.x + v.y * v.y));
	}

	//Normalise Vector2D (vector divided by its own magnitude)
	inline Vector2D Normalise(const Vector2D& v)
	{
		return (v / Magnitude(v));
	}

	//Vector2D to Vector2D addition
	inline Vector2D operator +(const Vector2D& a, const Vector2D& b)
	{
		return (Vector2D(a.x + b.x, a.y + b.y));
	}

	//Vector2D to Vector2D subtraction
	inline Vector2D operator -(const Vector2D& a, const Vector2D& b)
	{
		return (Vector2D(a.x - b.x, a.y - b.y));
	}

	//Vector2D to Vector2D dot product
	inline float Dot(const Vector2D& a, const Vector2D& b)
	{
		return (a.x * b.x + a.y * b.y);
	}

	//Vector2D to Matrix2X2 multiplication returns transformed vector2D
	Vector2D operator *(const Matrix2X2& M, const Vector2D& v);

	//Cross product for a 2D vector is not well defined, the sign of the value
	//returned here tells you whether the second vector is on the left or right
	//of the first.
	inline float Cross(const Vector2D& a, const Vector2D& b)
	{
		return a.x * b.y - a.y * b.x;
	}

	//Vector2D projection operation of 2D vector a onto 2D vector b
	inline Vector2D Project(const Vector2D& a, const Vector2D& b)
	{
		return (b * (Dot(a, b) / Dot(b, b)));
	}
	/*one of the primary functions of vector projection is a process
	known as orthagonalization, in which each memeber of a set of
	vectors is modified so that it is perpendicular to all other
	members of the set.*/

	//Vector2D rejection operation of 2D vector a from 2D vector b
	inline Vector2D Reject(const Vector2D& a, const Vector2D& b)
	{
		return (a - b * (Dot(a, b) / Dot(b, b)));
	}

}
#endif