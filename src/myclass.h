#ifndef __MYCLASS_H__
#define __MYCLASS_H__

#include <string>
#include <vector>

class myClass
{
public:
	myClass(const std::string& name, int age);
	int get_age();
	std::string get_name();

private:
	int m_age;
	std::string m_name;
};

int sum_integers(const std::vector<int> integers);

#endif
