#include "myclass.h"

myClass::myClass(const std::string& name, int age)
{
	m_age = age;
	m_name = name;
}

std::string myClass::get_name()
{
	return m_name;
}

int myClass::get_age()
{
	return m_age;
}

int sum_integers(const std::vector<int> integers)
{
	int sum = 0;
	for (auto i:integers)
	{
		sum += i;
	}
	return sum;
}
