#pragma once

#ifndef _MATRIX2X2
#define _MATRIX2X2

namespace mffg
{
	//Forward Declarations
	class Vector2D;

	//3x3 Matrix data structure
	class Matrix2X2
	{
		//3x3 array set up
		float n[2][2];

	public:

		//Default constructor
		Matrix2X2();

		//Destructor
		~Matrix2X2();

		//2x2 float matrix
		Matrix2X2(float n00, float n01,
				  float n10, float n11);

		//2x2 matrix, created from two 2D vectors
		Matrix2X2(const Vector2D& a, const Vector2D& b);

		//Return float from int i, j of the matrix
		float& operator ()(int i, int j);

		//Return constant float from int i, j of the matrix
		const float& operator ()(int i, int j) const;

		//Returns the specified row from the matrix into a 3D vector
		Vector2D& operator [](int j);

		//Returns the specified row from the matrix into a constant 3D vector
		const Vector2D& operator [](int j) const;
	};

	//Multiplication between two matrices returns new matrix result
	Matrix2X2 operator *(const Matrix2X2& A, const Matrix2X2& B);

	//Returns the Determinant of a 3x3 matrix
	float Determinant(const Matrix2X2& M);
}


#endif // !_MATRIX2X2
