#include "gtest/gtest.h"
#include "myclass.h"

TEST(myclass_test, get_name)
{
	myClass my_class("phil", 28);
	ASSERT_EQ(my_class.get_name(), "phil") << "name is not phil";
}

TEST(myclass_test, get_age)
{
	myClass my_class("phil", 24);
	ASSERT_TRUE(my_class.get_age()==28) << "age is not 28";
}
