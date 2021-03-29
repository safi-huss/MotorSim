#include <vector>
#include <algorithm>
#include <exception>

#include <arrayfire.h>

#include "Helper.h"
#include "Point3.h"
#include "CondElem.h"
#include "Conductor.h"

using af::array;
using std::vector;

af::array CConductor::GetArray()
{
	return m_afCondElements;
}

void CConductor::AddCondElem(CCondElem arg_objElem)
{
	m_vecCondElements.push_back(arg_objElem);
}

void CConductor::CreateArrayObjects()
{
	vector<float> vecArrayData;
	vecArrayData.resize(m_vecCondElements.size() * 3);

	auto iter_array = vecArrayData.begin();
	auto iter_cond = m_vecCondElements.begin();
	auto end_cond = m_vecCondElements.end();

	for (; iter_cond != end_cond; iter_cond++, iter_array += 3) {
		*(iter_array) = static_cast<float>(iter_cond->GetDirection().GetX());
		*(iter_array + 1) = static_cast<float>(iter_cond->GetDirection().GetY());
		*(iter_array + 2) = static_cast<float>(iter_cond->GetDirection().GetZ());
	}

	m_afCondElements = array(m_vecCondElements.size(), 3, vecArrayData.data());
}
