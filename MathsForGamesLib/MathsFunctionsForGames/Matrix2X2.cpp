#include "Matrix2X2.h"
#include "Vector2D.h"

namespace mffg
{

	Matrix2X2::Matrix2X2() = default;

	Matrix2X2::~Matrix2X2() {}

	Matrix2X2::Matrix2X2(float n00, float n01,
						 float n10, float n11)
	{
		n[0][0] = n00; n[0][1] = n01;
		n[1][0] = n10; n[1][1] = n11;
		
	}


	Matrix2X2::Matrix2X2(const Vector2D & a, const Vector2D & b)
	{
		n[0][0] = a.x; n[0][1] = a.y;
		n[1][0] = b.x; n[1][1] = b.y;
	}

	float& Matrix2X2::operator ()(int i, int j)
	{
		return (n[j][i]);
	}

	const float& Matrix2X2::operator ()(int i, int j) const
	{
		return (n[j][i]);
	}

	Vector2D& Matrix2X2::operator [](int j)
	{
		return (*reinterpret_cast<Vector2D*>(n[j]));
	}

	const Vector2D& Matrix2X2::operator [](int j) const
	{
		return (*reinterpret_cast<const Vector2D*>(n[j]));
	}

	Matrix2X2 operator *(const Matrix2X2& A, const Matrix2X2& B)
	{
		return (Matrix2X2(A(0, 0) * B(0, 0) + A(0, 1) * B(1, 0),
						  A(0, 0) * B(0, 1) + A(0, 1) * B(1, 1),
						  A(1, 0) * B(0, 0) + A(1, 1) * B(1, 0),
						  A(1, 0) * B(0, 1) + A(1, 1) * B(1, 1)));
	}

	float Determinant(const Matrix2X2& M)
	{
		return ((M(0, 0) * M(1, 1)) - (M(0, 1) * M(1, 0)));
	}
}