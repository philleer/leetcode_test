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
/**
 *=============================================================================
 * @Description : Solution for leetcode problem 0179
 * @Author      : phillee (email: phillee2016@163.com)
 * @Date        : 2022-01-10
 * @LICENSE     : Copyright (c) philleer 2022. All Rights Reserved.
 *=============================================================================
 */
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "ioutils.h"

class Solution {
public:
    // 179. Largest Number
    /*=====================================================================
     * Description: Given a list of non-negative integers nums, arrange
     *  them such that they form the largest number and return it.
     *  Since the result may be very large, so you need to return a string
     *  instead of an integer.
     *
     * Example:
     *  Input: nums = [10,2]    Output: "210"
     *
     *  Input: nums = [3,30,34,5,9] Output: "9534330"
     *
     *  Input: nums = [1,2,3,4,5,6,7,8,9,0] Output: "9876543210"
     *
     *  Input: nums = [0,0]    Output: "0"
     *
     * Constraints:
     *  1 <= nums.length <= 100
     *  0 <= nums[i] <= 10^9
     *=====================================================================
     */
    std::string myitos(int num)
    {
        std::string res;
        if (num==0)
            res = "0";
        int remainder = num%10;
        while (num!=0)
        {
            res += remainder+'0';
            num /= 10;
            remainder = num%10;
        }

        return std::string(res.rbegin(), res.rend());
    }

    std::vector<std::string> vec2str(std::vector<int> vec)
    {
        std::vector<std::string> res;

        int len = vec.size();
        if (len<1)
            return res;

        for (int i=0; i<len; i++)
        {
            res.emplace_back(myitos(vec[i]));
        }

        return res;
    }
    
	std::string largestNumber(std::vector<int>& nums) {
        std::string res;
        
        int len = nums.size();
        if (len < 1)
        {
            return res;
        }
        
        /* Transform int to string */
        std::vector<std::string> intstr = vec2str(nums);

        for (auto numstr: intstr)
            std::cout << numstr << std::endl;
        /* Iterate to find the larger str and continue */
        for (int i=0; i <intstr.size()-1; i++)
        {
            int tmp = i;
            for (int j=i; j<intstr.size(); j++)
            {
                if (intstr[j]+intstr[tmp]>intstr[tmp]+intstr[j])
                {
                    tmp = j;
                }
            }
            if (tmp!=i)
            {
                std::string str_tmp = intstr[i];
                intstr[i] = intstr[tmp];
                intstr[tmp] = str_tmp;
            }
        }
        
        for (int i=0; i<intstr.size(); i++)
        {
            if (intstr[i]=="0" && res=="0")
                continue;
            res += intstr[i];
        }
        
        return res;
    }

    std::string largestNumber_mostvoted(std::vector<int>& nums) {
        std::string res;
        
        int len = nums.size();
        if (len < 1)
        {
            return res;
        }
        
        /* Transform int to string */
        std::vector<std::string> intstr;
        for (int i=0; i<len; i++)
        {
            intstr.emplace_back(std::to_string(nums[i]));
        }

        std::sort(intstr.begin(), intstr.end(),
                  [](const std::string& a, const std::string& b)
                  { return a+b>b+a; }
                 );

        for (int i=0; i<intstr.size(); i++)
        {
            res += intstr[i];
        }
        
        return '0'==res[0] ? "0" : res;
    }
};

int main(int argc, char *argv[])
{
    std::string line;
    std::cout << "[Please input the data, seperate with space]" << std::endl;
    std::cout << "[like 3 30 34 5 9]" << std::endl;
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
        std::string res = Solution().largestNumber(nums);
        std::cout << "The processed result is : "
            << res << std::endl;
    }

    return 0;
}
