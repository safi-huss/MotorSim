#pragma once

class CCondElem
{
public:
	//Constructor(s)
	CCondElem() : m_fCrossSectionalArea(0.0), m_fMaterialConductivity(0.0), m_eObjectType(EObjectType::E_OBJECT_TYPE_FIXED) {}
	CCondElem(const CPoint3& arg_objStart, const CPoint3& arg_objEnd, const double& arg_fArea, const double& arg_fMatConductivity, EObjectType arg_eObjectType);
	CCondElem(const CCondElem& arg_objConductor);

	//Operator(s)
	void operator = (const CCondElem& arg_objConductor);

	//Destructor
	~CCondElem() {}

	//Get Function(s)
	CPoint3 GetStartPoint();
	CPoint3 GetEndPoint();
	CPoint3 GetDirection();
	double GetCrossSectionArea();
	double GetMaterialConductivity();
	EObjectType GetObjectType();
	double GetLength();
	double GetConductance();

	//Set Function(s)
	void SetStartPoint(CPoint3 arg_objStartPoint);
	void SetEndPoint(CPoint3 arg_objEndPoint);
	void SetCrossSectionArea(double arg_fCrossSectionArea);
	void SetMaterialConductivity(double arg_fMaterialConductivity);
	void SetObjectType(EObjectType arg_eObjectType);


private:
	CPoint3 m_objStart, m_objEnd;
	double m_fCrossSectionalArea;
	double m_fMaterialConductivity;
	EObjectType m_eObjectType;
};

