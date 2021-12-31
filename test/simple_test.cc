#include <stdio.h>
#include <vector>
#include "myclass.h"
#include "gtest/gtest.h"

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}

TEST(example, sum_zero)
{
	std::vector<int> integers = {1,-1,2,-2,3,-3};
	int res = sum_integers(integers);
	ASSERT_EQ(res, 0);
}

TEST(example, sum_five)
{
	std::vector<int> integers = {1,2,3,4,5};
	int res = sum_integers(integers);
	ASSERT_EQ(res, 15);
}
