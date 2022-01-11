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
#include <unordered_set>
#include "ioutils.h"

class Solution {
public:
    // 3. Longest Substring Without Repeating Characters
    /*=====================================================================
     * Description: Given a string s, find the length of the longest
     *  substring without repeating characters.
     *
     * Example:
     *      Input: s = "abcabcbb"	Output: 3
     *      Explanation: The answer is "abc", with the length of 3.
     *
     *      Input: s = "bbbbb"	Output: 1
     *      Explanation: The answer is "b", with the length of 1.
     *
     *      Input: s = "pwwkew"	Output: 3
     *      Explanation: The answer is "wke", with the length of 3.
     *      Notice that the answer must be a substring, "pwke" is a
     *      subsequence and not a substring.
     *
     * Constraints:
     *      0 <= s.length <= 5 * 10^4
     *      s consists of English letters, digits, symbols and spaces.
     *=====================================================================
     */
    int lengthOfLongestSubstring(std::string s) {
        int len = s.length();
        if (len<=1)
        	return len;

        std::string longest_sub;
        std::unordered_set<char> us;
	std::unordered_set<char>::iterator iter = us.begin();
        for (int i=0; i<len; i++)
        {
		iter = us.find(s[i]);
        	if (iter==us.end())
        	{
        		us.insert(s[i]);
        		longest_sub += s[i];
        	}
        	else
        	{
			std::cout << *iter << std::endl;
			iter++;
			longest_sub = std::string(iter, us.end());
        		//longest_sub += s[i];
        	}
        }
	std::cout << longest_sub << std::endl;

        return longest_sub.length();
    }
};

int main(int argc, char const *argv[]) {
    std::string line;
    std::cout << "[Please input the test data, seperate with space]" << std::endl;
    while (std::getline(std::cin, line)) {
        std::cout << "The input string is:"
                << line << std::endl;
        int res = Solution().lengthOfLongestSubstring(line);
        std::cout << "The processed result is : "
                << res << std::endl;
    }
    
    return 0;
}
