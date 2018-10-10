#include "Vector2D.h"
#include "Matrix2x2.h"

namespace mffg
{
	Vector2D::Vector2D() = default;

	Vector2D::~Vector2D() {}

	Vector2D::Vector2D(float a, float b)
	{
		x = a;
		y = b;
	}

	float& Vector2D::operator [](int i)
	{
		return ((&x)[i]);
	}

	const float& Vector2D::operator [](int i) const
	{
		return ((&x)[i]);
	}

	Vector2D& Vector2D::operator *=(float s)
	{
		x *= s;
		y *= s;
		return (*this);
	}

	Vector2D& Vector2D::operator /=(float s)
	{
		s = 1.0f / s;
		x *= s;
		y *= s;
		return (*this);
	}

	Vector2D& Vector2D::operator +=(const Vector2D& v)
	{
		x += v.x;
		y += v.y;
		return(*this);
	}

	Vector2D& Vector2D::operator -=(const Vector2D& v)
	{
		x -= v.x;
		y -= v.y;
		return(*this);
	}

	Vector2D operator *(const Matrix2X2& M, const Vector2D& v)
	{
		return (Vector2D(M(0, 0) * v.x + M(0, 1) * v.y,
						 M(1, 0) * v.x + M(1, 1) * v.y));
	}
}