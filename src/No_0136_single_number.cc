/******************************************************************************
 * The source is part of my C++ solution for leetcode problems.
 *
 * All of the codes can pass leetcode online judge, while also compiled and ran
 * on the offline machine
 * ============================================================================
 * //////////// Apple clang 13.0.0 (clang-1300.0.29.30) when on mac ///////////
 * /////////////////           G++5.4.0 when on Linux           ///////////////
 * ============================================================================
 * If any question, feel free to create an issue or Pull Request
 * @phillee<< phillee2016@163.com >>
 ******************************************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "ioutils.h"

extern "C"
{
#include "bitops.h"
}

class Solution {
public:
	// 136. Single Number
	/*=====================================================================
	 * Description: Given a non-empty array of integers nums, every element
	 *  appears twice except for one. Find that single one.
	 *	You must implement a solution with a linear runtime complexity and
	 *  use only constant extra space.
	 *
	 * Example:
	 *	Input: nums = [2,2,1]	Output: 1
	 *
	 *	Input: Input: nums = [4,1,2,1,2] 	Output: 4
	 *
	 *	Input: Input: nums = [1]	Output: 1
	 *
	 * Constraints:
	 *	1 <= nums.length <= 3 * 10^4
	 *	-3 * 10^4 <= nums[i] <= 3 * 10^4
	 *	Each element in the array appears twice except for one element
	 *	which appears only once.
	 *=====================================================================
	 */
	int singleNumber(std::vector<int>& nums) {
		int len = nums.size();
		if (len<=1)
			return nums.back();

		int res = 0;
		for (int i=0; i<len; i++)
		{
			res ^= nums[i];
		}

		return res;
	}
	// 137. Single Number II
	/*=====================================================================
	 * Description: Given an integer array nums where every element appears
	 *	three times except for one, which appears exactly once.
	 *	Find the single element and return it.
	 *	You must implement a solution with a linear runtime complexity and
	 *  use only constant extra space.
	 *
	 * Example:
	 *	Input: nums = [2,2,3,2]	Output: 3
	 *
	 *	Input: nums = [0,1,0,1,0,1,99] 	Output: 99
	 *
	 * Constraints:
	 *	1 <= nums.length <= 3 * 10^4
	 *	-2^31 <= nums[i] <= 2^31 - 1
	 *	Each element in the array appears exactly three times except for
	 *	one element which appears only once.
	 *=====================================================================
	 */
	int singleNumberII(std::vector<int>& nums) {
		int len = nums.size();
		if (len<=1)
			return nums.back();

		int shift = 1;
		int res = 0;
		for (int k=0; k<32; k++)
		{
			int tmp = 0;
			for (int i=0; i<len; i++)
			{
				if (nums[i] & shift)
					tmp += 1;
			}
			if (tmp%3!=0)
				res += shift;
			shift <<= 1;
		}

		return res;
	}

	// 260. Single Number III
	/*=====================================================================
	 * Description: Given an integer array nums, in which exactly two elements
	 *	appear only once and all the other elements appear exactly twice. 
	 *	Find the two elements that appear only once. You can return the
	 *	answer in any order.
	 *	You must write an algorithm that runs in linear runtime complexity
	 *  and use only constant extra space.
	 *
	 * Example:
	 *	Input: nums = [1,2,1,3,2,5]	Output: [3,5]
	 *	Explanation:  [5, 3] is also a valid answer.
	 *
	 *	Input: nums = [-1,0] 	Output: [-1,0]
	 *
	 *	Input: nums = [0,1]		Output: [1,0]
	 *
	 * Constraints:
	 *	2 <= nums.length <= 3 * 10^4
	 *	-2^31 <= nums[i] <= 2^31 - 1
	 *	Each integer in nums will appear twice, only two integers will
	 *	appear once.
	 *=====================================================================
	 */
	std::vector<int> singleNumberIII_sortbased(std::vector<int>& nums) {
		int len = nums.size();
		if (len <= 2)
		{
			return nums;
		}

		std::sort(nums.begin(), nums.end());

		std::vector<int> res;
		if (nums[0]!=nums[1])
			res.push_back(nums[0]);
		for (int i=1; i<len-1; i++)
		{
			if (nums[i]!=nums[i-1] && nums[i]!=nums[i+1])
				res.push_back(nums[i]);
		}
		if (nums.back() != nums[len-2])
			res.push_back(nums.back());

		return res;
	}
	std::vector<int> singleNumberIII_bitbased(std::vector<int>& nums) {
		int len = nums.size();
		if (len <= 2)
		{
			return nums;
		}
		std::vector<int> res{0, 0};
		int sum = 0;
		for (int i=0; i<len; i++) {
			sum ^= nums[i];
		}
		
		int lowbit = findRightmostOne(sum);
		for (int i=0; i<len; i++)
		{
			if (nums[i] & lowbit)
				res[0] ^= nums[i];
			else
				res[1] ^= nums[i];
		}

		return res;
	}
};

int main(int argc, char const *argv[]) {
	if (-1L < 1U)
	{
		printf("sizeof(unsigned int)=%ld, sizeof(signed long int)=%ld\n",
			   sizeof(unsigned int), sizeof(signed long int));
		printf("unsigned int is promoted to signed long type!\n");
	}
	if (-1L > 1UL)
	{
		printf("sizeof(signed long int)=%ld, sizeof(unsigned long int)=%ld\n",
			   sizeof(signed long int), sizeof(unsigned long int));
		printf("signed long is promoted to unsigned long type!\n");
	}
	std::cout << (signed int)0x80000000 << std::endl;
	std::cout << (signed int)0x7fffffff << std::endl;
	std::cout << "2^31-1=" << ((unsigned int)(1<<31)-1) << std::endl;
	std::cout << "-2^31=" << ((signed int)(1<<31)) << std::endl;

	std::cout << findRightmostOne(0x88) << std::endl;
	std::cout << findRightmostOne(0x7fffffff) << std::endl;
	std::cout << findRightmostOne(0x7ffffff0) << std::endl;
	std::cout << findRightmostOne(0x80000000) << std::endl;
	std::string line;
	std::cout << "[Please input the data, seperate with space]" << std::endl;
	while (std::getline(std::cin, line)) {
		std::stringstream ss;
		ss.str(line);
		std::string str;
		std::vector<int> nums;
		while (std::getline(ss, str, ' ')) {
			nums.push_back(std::atoi(str.c_str()));
		}

		std::string in = intVec2Str(nums);
		std::cout << "The input vector is:"
			<< in << std::endl;
		int res = Solution().singleNumber(nums);
		std::cout << "The processed result is : "
			<< res << std::endl;
	}

	return 0;
}
