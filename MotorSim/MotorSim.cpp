// MotorSim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "MotorSim.h"

using std::cout;
using std::endl;

int main()
{
	CConductor objStatorWindingU;

	for (float fWindingLoopZ = 0.0f; fWindingLoopZ < (10.0f - 0.4f); fWindingLoopZ += 0.4f) {
		CCondElem objElemRight(CPoint3(1.0, 1.0, fWindingLoopZ), CPoint3(1.0, -1.0, fWindingLoopZ + 0.1), 0.1, 0.1, EObjectType::E_OBJECT_TYPE_FIXED);
		objStatorWindingU.AddCondElem(objElemRight);
		CCondElem objElemBottom(CPoint3(1.0, -1.0, fWindingLoopZ + 0.1), CPoint3(-1.0, -1.0, fWindingLoopZ + 0.2), 0.1, 0.1, EObjectType::E_OBJECT_TYPE_FIXED);
		objStatorWindingU.AddCondElem(objElemBottom);
		CCondElem objElemLeft(CPoint3(-1.0, -1.0, fWindingLoopZ + 0.2), CPoint3(-1.0, 1.0, fWindingLoopZ + 0.3), 0.1, 0.1, EObjectType::E_OBJECT_TYPE_FIXED);
		objStatorWindingU.AddCondElem(objElemLeft);
		CCondElem objElemTop(CPoint3(-1.0, 1.0, fWindingLoopZ + 0.3), CPoint3(1.0, 1.0, fWindingLoopZ + 0.4), 0.1, 0.1, EObjectType::E_OBJECT_TYPE_FIXED);
		objStatorWindingU.AddCondElem(objElemTop);
	}

	objStatorWindingU.CreateArrayObjects();

	cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
