#include "Point3.h"

#include "Helper.h"

#include "CondElem.h"

CCondElem::CCondElem(const CPoint3& arg_objStart, const CPoint3& arg_objEnd, const double& arg_fArea, const double& arg_fMatConductivity, EObjectType arg_eObjectType)
	: m_objStart(arg_objStart)
	, m_objEnd(arg_objEnd)
	, m_fCrossSectionalArea(arg_fArea)
	, m_fMaterialConductivity(arg_fMatConductivity)
	, m_eObjectType(arg_eObjectType)
{}

CCondElem::CCondElem(const CCondElem & arg_objConductor)
{
	this->m_eObjectType = arg_objConductor.m_eObjectType;
	this->m_fCrossSectionalArea = arg_objConductor.m_fCrossSectionalArea;
	this->m_fMaterialConductivity = arg_objConductor.m_fMaterialConductivity;
	this->m_objEnd = arg_objConductor.m_objEnd;
	this->m_objStart = arg_objConductor.m_objStart;
}

void CCondElem::operator=(const CCondElem& arg_objConductor)
{
	this->m_eObjectType = arg_objConductor.m_eObjectType;
	this->m_fCrossSectionalArea = arg_objConductor.m_fCrossSectionalArea;
	this->m_fMaterialConductivity = arg_objConductor.m_fMaterialConductivity;
	this->m_objEnd = arg_objConductor.m_objEnd;
	this->m_objStart = arg_objConductor.m_objStart;
}

CPoint3 CCondElem::GetStartPoint()
{
	return m_objStart;
}

CPoint3 CCondElem::GetEndPoint()
{
	return m_objEnd;
}

CPoint3 CCondElem::GetDirection()
{
	return (m_objEnd - m_objStart).Normalize();
}

double CCondElem::GetCrossSectionArea()
{
	return m_fCrossSectionalArea;
}

double CCondElem::GetMaterialConductivity()
{
	return m_fMaterialConductivity;
}

EObjectType CCondElem::GetObjectType()
{
	return m_eObjectType;
}

double CCondElem::GetLength()
{
	return (m_objEnd - m_objStart).Mag();
}

double CCondElem::GetConductance()
{
	return this->GetLength() * m_fMaterialConductivity / m_fCrossSectionalArea;
}

void CCondElem::SetStartPoint(CPoint3 arg_objStartPoint)
{
	this->m_objStart = arg_objStartPoint;
}

void CCondElem::SetEndPoint(CPoint3 arg_objEndPoint)
{
	this->m_objEnd = arg_objEndPoint;
}

void CCondElem::SetCrossSectionArea(double arg_fCrossSectionArea)
{
	this->m_fCrossSectionalArea = arg_fCrossSectionArea;
}

void CCondElem::SetMaterialConductivity(double arg_fMaterialConductivity)
{
	this->m_fMaterialConductivity = arg_fMaterialConductivity;
}

void CCondElem::SetObjectType(EObjectType arg_eObjectType)
{
	this->m_eObjectType = arg_eObjectType;
}
