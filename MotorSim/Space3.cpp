#include <vector>
#include <algorithm>
#include <exception>

#include <arrayfire.h>

#include "Point3.h"

#include "Space3.h"

using std::vector;

CSpace3::CSpace3()
	: m_fVoxelSize(0.1)
	, m_objStartPoint(CPoint3(10.0, 10.0, 10.0))
	, m_objEndPoint(CPoint3(-10.0, -10.0, -10.0))
{
}

CSpace3::CSpace3(const CPoint3& arg_objStart, const CPoint3& arg_objEnd, const double& arg_fVoxelSize = 0.1)
	: m_objStartPoint(arg_objStart)
	, m_objEndPoint(arg_objEnd)
	, m_fVoxelSize(arg_fVoxelSize)
{
}

CSpace3::CSpace3(const CSpace3& arg_objSpace)
{
	this->m_objStartPoint = arg_objSpace.m_objStartPoint;
	this->m_objEndPoint = arg_objSpace.m_objEndPoint;
	this->m_fVoxelSize = arg_objSpace.m_fVoxelSize;
}

CSpace3::~CSpace3()
{
}

CPoint3 CSpace3::GetStartPoint()
{
	return m_objStartPoint;
}

CPoint3 CSpace3::GetEndPoint()
{
	return m_objEndPoint;
}

double CSpace3::GetVoxelSize()
{
	return m_fVoxelSize;
}

af::array CSpace3::GetListArray()
{
	vector<float> vecPointList;

	double fMinX = (m_objStartPoint.GetX() > m_objEndPoint.GetX()) ? (m_objEndPoint.GetX()) : (m_objStartPoint.GetX());
	double fMinY = (m_objStartPoint.GetY() > m_objEndPoint.GetY()) ? (m_objEndPoint.GetY()) : (m_objStartPoint.GetY());
	double fMinZ = (m_objStartPoint.GetZ() > m_objEndPoint.GetZ()) ? (m_objEndPoint.GetZ()) : (m_objStartPoint.GetZ());
	double fMaxX = (m_objStartPoint.GetX() < m_objEndPoint.GetX()) ? (m_objEndPoint.GetX()) : (m_objStartPoint.GetX());
	double fMaxY = (m_objStartPoint.GetY() < m_objEndPoint.GetY()) ? (m_objEndPoint.GetY()) : (m_objStartPoint.GetY());
	double fMaxZ = (m_objStartPoint.GetZ() < m_objEndPoint.GetZ()) ? (m_objEndPoint.GetZ()) : (m_objStartPoint.GetZ());

	for (double iter_fx = fMinX; iter_fx < fMaxX; iter_fx += m_fVoxelSize) {
		for (double iter_fy = fMinY; iter_fy < fMaxY; iter_fy += m_fVoxelSize) {
			for (double iter_fz = fMinZ; iter_fz < fMaxZ; iter_fz += m_fVoxelSize) {
				vecPointList.push_back(static_cast<float>(iter_fx));
				vecPointList.push_back(static_cast<float>(iter_fy));
				vecPointList.push_back(static_cast<float>(iter_fz));
			}
		}
	}

	return af::array(vecPointList.size(), 3, vecPointList.data());
}

void CSpace3::SetSpan(const CPoint3& arg_objStart, const CPoint3& arg_objEnd)
{
	this->m_objStartPoint = arg_objStart;
	this->m_objEndPoint = arg_objEnd;
}

void CSpace3::SetVoxelSize(const double& arg_fVoxelSize)
{
	this->m_fVoxelSize = arg_fVoxelSize;
}

void CSpace3::operator=(const CSpace3& arg_objSpace)
{
	this->m_objStartPoint = arg_objSpace.m_objStartPoint;
	this->m_objEndPoint = arg_objSpace.m_objEndPoint;
	this->m_fVoxelSize = arg_objSpace.m_fVoxelSize;
}
