#pragma once
#include "Matrix3x3.h"
#include "Vector3D.h"

namespace mffg
{

	Matrix3X3::Matrix3X3() = default;

	Matrix3X3::~Matrix3X3() {}

	Matrix3X3::Matrix3X3(float n00, float n01, float n02,
		float n10, float n11, float n12,
		float n20, float n21, float n22)
	{
		n[0][0] = n00; n[0][1] = n01; n[0][2] = n02;
		n[1][0] = n10; n[1][1] = n11; n[1][2] = n12;
		n[2][0] = n20; n[2][1] = n21; n[2][2] = n22;
	}


	Matrix3X3::Matrix3X3(const Vector2D & a, const Vector2D & b, const Vector2D & c)
	{
		n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
		n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
		n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
	}

	float& Matrix3X3::operator ()(int i, int j)
	{
		return (n[j][i]);
	}

	const float& Matrix3X3::operator ()(int i, int j) const
	{
		return (n[j][i]);
	}

	Vector2D& Matrix3X3::operator [](int j)
	{
		return (*reinterpret_cast<Vector2D*>(n[j]));
	}

	const Vector2D& Matrix3X3::operator [](int j) const
	{
		return (*reinterpret_cast<const Vector2D*>(n[j]));
	}

	Matrix3X3 operator *(const Matrix3X3& A, const Matrix3X3& B)
	{
		return (Matrix3X3(A(0, 0) * B(0, 0) + A(0, 1) * B(1, 0) + A(0, 2) * B(2, 0),
			A(0, 0) * B(0, 1) + A(0, 1) * B(1, 1) + A(0, 2) * B(2, 1),
			A(0, 0) * B(0, 2) + A(0, 1) * B(1, 2) + A(0, 2) * B(2, 2),
			A(1, 0) * B(0, 0) + A(1, 1) * B(1, 0) + A(1, 2) * B(2, 0),
			A(1, 0) * B(0, 1) + A(1, 1) * B(1, 1) + A(1, 2) * B(2, 1),
			A(1, 0) * B(0, 2) + A(1, 1) * B(1, 2) + A(1, 2) * B(2, 2),
			A(2, 0) * B(0, 0) + A(2, 1) * B(1, 0) + A(2, 2) * B(2, 0),
			A(2, 0) * B(0, 1) + A(2, 1) * B(1, 1) + A(2, 2) * B(2, 1),
			A(2, 0) * B(0, 2) + A(2, 1) * B(1, 2) + A(2, 2) * B(2, 2)));
	}

	float Determinant(const Matrix3X3& M)
	{
		return (M(0, 0) * (M(1, 1) * M(2, 2) - M(1, 2) * M(2, 1))
			  + M(0, 0) * (M(1, 1) * M(2, 2) - M(1, 2) * M(2, 1))
			  + M(0, 0) * (M(1, 1) * M(2, 2) - M(1, 2) * M(2, 1)));
	}
}