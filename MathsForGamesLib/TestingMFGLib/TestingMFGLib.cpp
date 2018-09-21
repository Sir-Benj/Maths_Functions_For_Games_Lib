// TestingMFGLib.cpp : Defines the entry point for the console application.
//
#pragma once
#include "Vector3D.h"
#include "Matrix3x3.h"
#include <iostream>

using namespace std;
using namespace mffg;

void nL();

int main()
{
	Vector3D testVec(2, 1, 3);
	Vector3D testVec2(4, 2, 6);

	Matrix3X3 testMat(3, 4, 8,
					  4, 2, 3,
					  7, 4, 12);

	for (int i = 0; i < 3; i++)
	{
		cout << testVec[i] << " ";
	}

	nL();

	Vector3D matToVec = testMat[0];

	for (int i = 0; i < 3; i++)
	{
		cout << matToVec[i] << " ";
	}

	nL();

	testVec = testMat * testVec;

	for (int i = 0; i < 3; i++)
	{
		cout << testVec[i] << " ";
	}

	nL();

	float testMatDet = Determinant(testMat);

	cout << testMatDet << endl;
	
	/*testVec *= 10;

	for (int i = 0; i < 3; i++)
	{
		cout << testVec[i] << " Multiplication" << endl;
	}

	testVec /= 3;

	for (int i = 0; i < 3; i++)
	{
		cout << testVec[i] << " Division" << endl;
	}

	Normalise(testVec);

	for (int i = 0; i < 3; i++)
	{
		cout << testVec[i] << " Normalised" << endl;
	}

	float magVec = Magnitude(testVec);

	cout << magVec << " Magnitude" << endl;

	testVec += testVec2;

	for (int i = 0; i < 3; i++)
	{
		cout << testVec[i] << " Addition" << endl;
	}

	testVec -= testVec2;

	for (int i = 0; i < 3; i++)
	{
		cout << testVec[i] << " Subtraction" << endl;
	}*/

    return 0;
}

void nL()
{
	cout << endl;
}

