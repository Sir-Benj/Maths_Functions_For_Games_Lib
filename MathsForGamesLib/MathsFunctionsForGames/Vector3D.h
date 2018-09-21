#pragma once
#include "math.h"


#ifndef _VECTOR3D
#define _VECTOR3D

namespace mffg
{
	//Forward Declarations
	class Matrix3X3;

	//Vector class for 3D
	class Vector3D
	{
	public:

		float x, y, z;

		//Default constructor
		Vector3D();

		//Destructor
		~Vector3D();

		//Three point float constructor for vector3D
		Vector3D(float a, float b, float c);

		//Return point from vector
		float& operator [](int i);

		//Return constant point from vector
		const float& operator [](int i) const;

		//Vector3D multiplication with scalar by *= operation
		Vector3D& operator *=(float s);

		//Vector3D division with scalar by /= operation
		Vector3D& operator /=(float s);

		//Vector3D to Vector 3D addition by += operation
		Vector3D& operator +=(const Vector3D& v);

		//Vector3D to Vector 3D subtraction by -= operation
		Vector3D& operator -=(const Vector3D& v);
	};

	//Vector3D with scalar multiplication 
	inline Vector3D operator *(const Vector3D& v, float s)
	{
		return Vector3D(v.x * s, v.y * s, v.z * s);
	}

	//Vector3D with scalar division
	inline Vector3D operator /(const Vector3D& v, float s)
	{
		s = 1.0f / s;
		return (Vector3D(v.x * s, v.y * s, v.z * s));
	}

	//Vector3D sign negative
	inline Vector3D operator -(const Vector3D& v)
	{
		return (Vector3D(-v.x, -v.y, -v.z));
	}

	//Calculate Magnitude of Vector3D
	inline float Magnitude(const Vector3D& v)
	{
		return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	}

	//Normalise Vector3D (vector divided by its own magnitude)
	inline Vector3D Normalise(const Vector3D& v)
	{
		return (v / Magnitude(v));
	}

	//Vector3D to Vector3D addition
	inline Vector3D operator +(const Vector3D& a, const Vector3D& b)
	{
		return (Vector3D(a.x + b.x, a.y + b.y, a.z + b.z));
	}

	//Vector3D to Vector3D subtraction
	inline Vector3D operator -(const Vector3D& a, const Vector3D& b)
	{
		return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
	}

	//Vector3D to Vector3D dot product
	inline float Dot(const Vector3D& a, const Vector3D& b)
	{
		return (a.x * b.x + a.y * b.y + a.z * b.z);
	}

	//Vector3D to Matrix3X3 multiplication returns transformed vector3D
	Vector3D operator *(const Matrix3X3& M, const Vector3D& v);

	//Vector3D cross product between two 3D vector data structures
	inline Vector3D Cross(const Vector3D& a, const Vector3D& b)
	{
		return (Vector3D(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x));
	}

	//Vector3D projection operation of 3D vector a onto 3D vector b
	inline Vector3D Project(const Vector3D& a, const Vector3D& b)
	{
		return (b * (Dot(a, b) / Dot(b, b)));
	}
	/*one of the primary functions of vector projection is a process
	known as orthagonalization, in which each memeber of a set of
	vectors is modified so that it is perpendicular to all other
	members of the set.*/

	//Vector3D rejection operation of 3D vector a from 3D vector b
	inline Vector3D Reject(const Vector3D& a, const Vector3D& b)
	{
		return (a - b * (Dot(a, b) / Dot(b, b)));
	}

}
#endif