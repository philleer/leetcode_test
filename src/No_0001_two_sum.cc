/******************************************************************************
 * The source is part of my C++ solution for leetcode problems.
 *
 * All of the codes can pass leetcode online judge, while also compiled and ran
 * on the offline machine
 * ============================================================================
 * //////////// Apple clang 13.0.0 (clang-1300.0.29.30) when on mac ///////////
 * /////////////////           G++7.5.0 when on Linux           ///////////////
 * ============================================================================
 * If any question, feel free to create an issue or Pull Request
 * @phillee<< phillee2016@163.com >>
 ******************************************************************************
 */
/**
 *=============================================================================
 * @Description : Test for leetcode problems 001
 * @Version     : 1.0
 * @Author      : phillee (email: phillee2016@163.com)
 * @Date        : 2022-01-07
 * @LICENSE     : Copyright (c) philleer 2022. All Rights Reserved.
 *=============================================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include "ioutils.h"

class Solution {
public:
    // 1. Two Sum
    /*=====================================================================
     * Description: Given an array of integers nums and an integer target,
     *  return indices of the two numbers such that they add up to target.
     *  You may assume that each input would have exactly one solution, and
     *  you may not use the same element twice.
     *  You can return the answer in any order.
     *
     * Example:
     *      Input: nums = [2,7,11,15], target = 9	Output: [0,1]
     *      Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
     *
     *      Input: nums = [3,2,4], target = 6	Output: [1,2]
     *
     *      Input: nums = [3,3], target = 6		Output: [0,1]
     *
     * Constraints:
     *      2 <= nums.length <= 10^4
     *      -10^9 <= nums[i] <= 10^9
     *      -10^9 <= target <= 10^9
     *      Only one valid answer exists.
     *=====================================================================
     */
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> res;
        int len = nums.size();
        if (len<=1 || (len==2 && nums[0]+nums[1]!=target))
        	return res;

        std::unordered_map<int, int> mp;
        for (int i=0; i<len; i++)
        {
        	if (mp.find(target-nums[i])!=mp.end())
        	{
        		res.push_back(mp[target-nums[i]]);
        		res.push_back(i);
        		break;
        	}
        	else
        	{
        		mp[nums[i]] = i;
        	}
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    std::string line;
    std::cout << "[Please input the test data, seperate with space]" << std::endl;
    while (std::getline(std::cin, line)) {
        std::stringstream ss;
        ss.str(line);
        std::string str;
        std::vector<int> invec;
        while (std::getline(ss, str, ' ')) {
            invec.push_back(std::atoi(str.c_str()));
        }

        std::vector<int> nums(invec.begin(), invec.end()-1);
        int target = invec.back();
    
        std::string instr = intVec2Str(nums);
        std::cout << "The input vector is:"
                << instr << std::endl;
	std::vector<int> res = Solution().twoSum(nums, target);
        std::string resstr = intVec2Str(res);
        std::cout << "The processed result is : "
                << resstr << std::endl;
    }
    
    return 0;
}
