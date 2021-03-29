#include <cmath>

#include "Point3.h"

void CPoint3::operator=(const CPoint3& arg_objP)
{
	this->m_fX = arg_objP.m_fX;
	this->m_fY = arg_objP.m_fY;
	this->m_fZ = arg_objP.m_fZ;
}

CPoint3 CPoint3::operator+(const CPoint3& arg_fP)
{
	return CPoint3(this->m_fX + arg_fP.m_fX, this->m_fY + arg_fP.m_fY, this->m_fZ + arg_fP.m_fZ);
}

CPoint3 CPoint3::operator-(const CPoint3& arg_fP)
{
	return CPoint3(this->m_fX - arg_fP.m_fX, this->m_fY - arg_fP.m_fY, this->m_fZ - arg_fP.m_fZ);
}

CPoint3 CPoint3::operator*(const CPoint3& arg_fP)
{
	return CPoint3(this->m_fX * arg_fP.m_fX, this->m_fY * arg_fP.m_fY, this->m_fZ * arg_fP.m_fZ);
}

CPoint3 CPoint3::operator/(const CPoint3& arg_fP)
{
	return CPoint3(this->m_fX / arg_fP.m_fX, this->m_fY / arg_fP.m_fY, this->m_fZ / arg_fP.m_fZ);
}

CPoint3 CPoint3::operator+(const double& arg_fS)
{
	return CPoint3(this->m_fX + arg_fS, this->m_fY + arg_fS, this->m_fZ + arg_fS);
}

CPoint3 CPoint3::operator-(const double& arg_fS)
{
	return CPoint3(this->m_fX - arg_fS, this->m_fY - arg_fS, this->m_fZ - arg_fS);
}

CPoint3 CPoint3::operator*(const double& arg_fS)
{
	return CPoint3(this->m_fX * arg_fS, this->m_fY * arg_fS, this->m_fZ * arg_fS);
}

CPoint3 CPoint3::operator/(const double& arg_fS)
{
	return CPoint3(this->m_fX / arg_fS, this->m_fY / arg_fS, this->m_fZ / arg_fS);
}

double CPoint3::GetX()
{
	return m_fX;
}

double CPoint3::GetY()
{
	return m_fY;
}

double CPoint3::GetZ()
{
	return m_fZ;
}

void CPoint3::SetX(double arg_fX)
{
	m_fX = arg_fX;
}

void CPoint3::SetY(double arg_fY)
{
	m_fY = arg_fY;
}

void CPoint3::SetZ(double arg_fZ)
{
	m_fZ = arg_fZ;
}

void CPoint3::Set(double arg_fX, double arg_fY, double arg_fZ)
{
	m_fX = arg_fX;
	m_fY = arg_fY;
	m_fZ = arg_fZ;
}

double CPoint3::Mag()
{
	return sqrt(m_fX*m_fX + m_fY*m_fY + m_fZ*m_fZ);
}

double CPoint3::Displacement(const CPoint3& arg_objP)
{
	return ((*this) - arg_objP).Mag();
}

double CPoint3::Dot(const CPoint3& arg_objP)
{
	return ((*this) * arg_objP).Mag();
}

CPoint3 CPoint3::Cross(const CPoint3& arg_objP)
{
	return CPoint3((this->m_fY * arg_objP.m_fZ) - (this->m_fZ * arg_objP.m_fY), 
				   (this->m_fZ * arg_objP.m_fX) - (this->m_fX * arg_objP.m_fZ), 
				   (this->m_fX * arg_objP.m_fY) - (this->m_fY * arg_objP.m_fX));
}

CPoint3 CPoint3::Normalize()
{
	return (*this) / this->Mag();
}

CPoint3 operator+(const double& arg_fS, CPoint3 arg_objP)
{
	return (arg_objP + arg_fS);
}

CPoint3 operator-(const double& arg_fS, CPoint3 arg_objP)
{
	return (arg_objP - arg_fS);
}

CPoint3 operator*(const double& arg_fS, CPoint3 arg_objP)
{
	return (arg_objP * arg_fS);
}

CPoint3 operator/(const double& arg_fS, CPoint3 arg_objP)
{
	return (arg_objP / arg_fS);
}
