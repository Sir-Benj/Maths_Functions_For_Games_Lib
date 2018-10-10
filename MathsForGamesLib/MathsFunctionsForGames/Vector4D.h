#pragma once
#include "math.h"

#ifndef _VECTOR4D
#define _VECTOR4D

namespace mffg
{
	//Forward Declarations
	class Matrix4X4;

	//Vector class for 4D
	class Vector4D
	{
	public:

		float x, y, z, w;

		//Default constructor
		Vector4D();

		//Destructor
		~Vector4D();

		//Three point float constructor for vector4D
		Vector4D(float a, float b, float c, float d);

		//Return point from vector
		float& operator [](int i);

		//Return constant point from vector
		const float& operator [](int i) const;

		//Vector4D multiplication with scalar by *= operation
		Vector4D& operator *=(float s);

		//Vector4D division with scalar by /= operation
		Vector4D& operator /=(float s);

		//Vector4D to Vector 4D addition by += operation
		Vector4D& operator +=(const Vector4D& v);

		//Vector4D to Vector 4D subtraction by -= operation
		Vector4D& operator -=(const Vector4D& v);
	};

	//Vector4D with scalar multiplication 
	inline Vector4D operator *(const Vector4D& v, float s)
	{
		return Vector4D(v.x * s, v.y * s, v.z * s, v.w * s);
	}

	//Vector4D with scalar division
	inline Vector4D operator /(const Vector4D& v, float s)
	{
		s = 1.0f / s;
		return (Vector4D(v.x * s, v.y * s, v.z * s, v.w * s));
	}

	//Vector3D sign negative
	inline Vector4D operator -(const Vector4D& v)
	{
		return (Vector4D(-v.x, -v.y, -v.z, -v.w));
	}
}
#endif