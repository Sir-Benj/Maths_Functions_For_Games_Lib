#pragma once
#include "math.h"

#ifndef _MATRIX3X3
#define _MATRIX3X3

namespace mffg
{
	//Forward Declarations
	class Vector3D;

	//3x3 Matrix data structure
	class Matrix3X3
	{
		//3x3 array set up
		float n[3][3];

	public:

		//Default constructor
		Matrix3X3();

		//Destructor
		~Matrix3X3();

		//3x3 float matrix
		Matrix3X3(float n00, float n01, float n02,
			float n10, float n11, float n12,
			float n20, float n21, float n22);

		//3x3 matrix, created from three 3D vectors
		Matrix3X3(const Vector3D& a, const Vector3D& b, const Vector3D& c);

		//Return float from int i, j of the matrix
		float& operator ()(int i, int j);

		//Return constant float from int i, j of the matrix
		const float& operator ()(int i, int j) const;

		//Returns the specified row from the matrix into a 3D vector
		Vector3D& operator [](int j);

		//Returns the specified row from the matrix into a constant 3D vector
		const Vector3D& operator [](int j) const;
	};

	//Multiplication between two matrices returns new matrix result
	Matrix3X3 operator *(const Matrix3X3& A, const Matrix3X3& B);

	//Returns the Determinant of a 3x3 matrix
	float Determinant(const Matrix3X3& M);
}	


#endif