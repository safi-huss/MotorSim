#pragma once

class CPoint3
{
public:
	//Constructor(s)
	CPoint3() : m_fX(0.0), m_fY(0.0), m_fZ(0.0) { }
	CPoint3(double arg_fX, double arg_fY, double arg_fZ) : m_fX(arg_fX), m_fY(arg_fY), m_fZ(arg_fZ) {}
	CPoint3(const CPoint3& arg_objP) { (*this) = arg_objP; }

	//Overloaded operator(s)
	void operator = (const CPoint3& arg_objP);
	CPoint3 operator + (const CPoint3& arg_fS);
	CPoint3 operator - (const CPoint3& arg_fS);
	CPoint3 operator * (const CPoint3& arg_fS);
	CPoint3 operator / (const CPoint3& arg_fS);
	CPoint3 operator + (const double& arg_fS);
	CPoint3 operator - (const double& arg_fS);
	CPoint3 operator * (const double& arg_fS);
	CPoint3 operator / (const double& arg_fS);

	friend CPoint3 operator + (const double& arg_fS, CPoint3 arg_objP);
	friend CPoint3 operator - (const double& arg_fS, CPoint3 arg_objP);
	friend CPoint3 operator * (const double& arg_fS, CPoint3 arg_objP);
	friend CPoint3 operator / (const double& arg_fS, CPoint3 arg_objP);

	//Get Function(s)
	double GetX();
	double GetY();
	double GetZ();

	//Set Function(s)
	void SetX(double arg_fX);
	void SetY(double arg_fY);
	void SetZ(double arg_fZ);
	void Set(double arg_fX, double arg_fY, double arg_fZ);

	//Member Function(s)
	double Mag();
	double Displacement(const CPoint3& arg_objP);
	double Dot(const CPoint3& arg_objP);
	CPoint3 Cross(const CPoint3& arg_objP);
	CPoint3 Normalize();

protected:
	double m_fX, m_fY, m_fZ;
};

