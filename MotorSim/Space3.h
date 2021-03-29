#pragma once

class CSpace3
{
public:
	//Constructor(s)
	CSpace3();
	CSpace3(const CPoint3& arg_objStart, const CPoint3& arg_objEnd, const double& arg_fVoxelSize);
	CSpace3(const CSpace3& arg_objSpace);

	//Destructor
	~CSpace3();

	//Get Function(s)
	CPoint3 GetStartPoint();
	CPoint3 GetEndPoint();
	double GetVoxelSize();
	af::array GetListArray();
	af::array Get3DArray();

	//Set Function(s)
	void SetSpan(const CPoint3& arg_objStart, const CPoint3& arg_objEnd);
	void SetVoxelSize(const double& arg_fVoxelSize);

	//Overloaded Operator
	void operator = (const CSpace3& arg_objSpace);

	//Member Function(s)
	void CreateArrayObjects();

private:
	CPoint3 m_objStartPoint, m_objEndPoint;
	double m_fVoxelSize;

	af::array m_afPointsList;
};

