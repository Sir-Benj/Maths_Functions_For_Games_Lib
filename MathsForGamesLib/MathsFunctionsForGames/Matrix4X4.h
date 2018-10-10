#pragma once
#include "math.h"

#ifndef _MATRIX4X4
#define _MATRIX4X4

namespace mffg
{
	//Forward Declarations
	class Vector4D;

	//3x3 Matrix data structure
	class Matrix4X4
	{
		//3x3 array set up
		float n[4][4];

	public:

		//Default constructor
		Matrix4X4();

		//Destructor
		~Matrix4X4();

		//4x4 float matrix
		Matrix4X4(float n00, float n01, float n02, float n03,
			float n10, float n11, float n12, float n13,
			float n20, float n21, float n22, float n23,
			float n30, float n31, float n32, float n33);

		//4x4 matrix, created from four 4D vectors
		Matrix4X4(const Vector4D& a, const Vector4D& b, const Vector4D& c, const Vector4D& d);

		//Return float from int i, j of the matrix
		float& operator ()(int i, int j);

		//Return constant float from int i, j of the matrix
		const float& operator ()(int i, int j) const;

		//Returns the specified row from the matrix into a 4D vector
		Vector4D& operator [](int j);

		//Returns the specified row from the matrix into a constant 4D vector
		const Vector4D& operator [](int j) const;
	};
}

#endif