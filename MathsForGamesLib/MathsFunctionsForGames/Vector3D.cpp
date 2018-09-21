// compile with: cl /c /EHsc Vector3D.cpp
// post-build command: lib Vector3D.obj

#pragma once
#include "Vector3D.h"
#include "Matrix3x3.h"

namespace mffg
{
	Vector3D::Vector3D() = default;

	Vector3D::~Vector3D() {}

	Vector3D::Vector3D(float a, float b, float c)
	{
		x = a;
		y = b;
		z = c;
	}

	float& Vector3D::operator [](int i)
	{
		return ((&x)[i]);
	}

	const float& Vector3D::operator [](int i) const
	{
		return ((&x)[i]);
	}

	Vector3D& Vector3D::operator *=(float s)
	{
		x *= s;
		y *= s;
		z *= s;
		return (*this);
	}

	Vector3D& Vector3D::operator /=(float s)
	{
		s = 1.0f / s;
		x *= s;
		y *= s;
		z *= s;
		return (*this);
	}

	Vector3D& Vector3D::operator +=(const Vector3D& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return(*this);
	}

	Vector3D& Vector3D::operator -=(const Vector3D& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return(*this);
	}

	Vector3D operator *(const Matrix3X3& M, const Vector3D& v)
	{
		return (Vector3D(M(0, 0) * v.x + M(0, 1) * v.y + M(0, 2) * v.z,
			M(1, 0) * v.x + M(1, 1) * v.y + M(1, 2) * v.z,
			M(2, 0) * v.x + M(2, 1) * v.y + M(2, 2) * v.z));
	}
}