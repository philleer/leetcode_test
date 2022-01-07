#include <stdio.h>
#include "ioutils.h"

void print_vector(const std::vector<int>& vec)
{
	int cols = vec.size();
	if (0==cols)
		return ;
	printf("[");
	for (int x=0; x<cols-1; x++)
	{
		printf("%4d, ", vec[x]);
	}
	printf("%4d]", vec.back());
}

void print_2d_vector(const std::vector<std::vector<int>>& vec)
{
	int rows = vec.size();

	printf("[");
	for (int y=0; y<rows-1; y++)
	{
		print_vector(vec[y]);
		printf("\n ");
	}
	print_vector(vec.back());
	printf("]\n");
}

std::string intVec2Str(std::vector<int> list)
{
	int len = list.size();
	if (0==len)
		return "[]";

	std::string res("[");
	for(int idx = 0; idx < len-1; ++idx) {
		res += std::to_string(list[idx]) + ", ";
	}
	res += std::to_string(list.back()) + "]";

	return res;
}