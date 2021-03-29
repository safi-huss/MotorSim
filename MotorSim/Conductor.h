#pragma once

class CConductor
{
public:
	//Constructor(s)
	CConductor() {}

	//Destructor
	~CConductor() {}

	//Get Function(s)
	af::array GetArray();

	//Set Function(s)

	//Member Function(s)
	void AddCondElem(CCondElem arg_objElem);
	void CreateArrayObjects();

private:
	std::vector<CCondElem> m_vecCondElements;
	af::array m_afCondElements;
};
