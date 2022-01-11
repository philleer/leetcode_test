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
 * @Description : Solution for leetcode problem 0013
 * @Author      : phillee (email: phillee2016@163.com)
 * @Date        : 2022-01-11
 * @LICENSE     : Copyright (c) philleer 2022. All Rights Reserved.
 *=============================================================================
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

std::unordered_map<char, int> romanA = {{'I',1}, {'V',5}, {'X',10}, {'L',50},
                                            {'C',100}, {'D',500}, {'M',1000}};

class Solution
{
public:
    // 13. Roman to Integer
    /*=====================================================================
     * Description: 
     *	Roman numerals are represented by seven different symbols: I, V, X,
     *  L, C, D and M.
     *
     *		Symbol       Value
     *		I             1
     *		V             5
     *		X             10
     *		L             50
     *		C             100
     *		D             500
     *		M             1000
     *		
     *	For example, 2 is written as II in Roman numeral, just two one's
     *	added together. 12 is written as XII, which is simply X + II. The
     *	number 27 is written as XXVII, which is XX + V + II.
     *		
     *	Roman numerals are usually written largest to smallest from left to
     *	right. However, the numeral for four is not IIII. Instead, the number
     *	four is written as IV. Because the one is before the five we subtract
     *	it making four. The same principle applies to the number nine, which
     *	is written as IX. There are six instances where subtraction is used:
     *
     *      I can be placed before V (5) and X (10) to make 4 and 9. 
     *      X can be placed before L (50) and C (100) to make 40 and 90. 
     *      C can be placed before D (500) and M (1000) to make 400 and 900.
     *      Given a roman numeral, convert it to an integer.
     *
     * Example:
     *    Input: s = "III"
     *    Output: 3
     *    Explanation: III = 3.
     *	
     *    Input: s = "LVIII"
     *    Output: 58
     *    Explanation: L = 50, V= 5, III = 3.
     *	
     *    Input: s = "MCMXCIV"
     *    Output: 1994
     *    Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
     *
     * Constraints:
     *    1 <= s.length <= 15
     *    s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
     *    It is guaranteed that s is a valid roman numeral in the range
     *    [1, 3999].
     *=====================================================================
     */
    int romanToInt_naive(std::string s) {
        int res = 0;

        int i=0;
        while (s[i]!='\0')
        {
            if (s[i+1]!='\0' && (s[i]=='I'||s[i]=='X'||s[i]=='C'))
            {
                if ((s[i]=='I' && (s[i+1]=='V'||s[i+1]=='X')) ||
                    (s[i]=='X' && (s[i+1]=='L'||s[i+1]=='C')) ||
                    (s[i]=='C' && (s[i+1]=='D'||s[i+1]=='M')))
                {
                    res += romanA[s[i+1]]-romanA[s[i]];
                    ++i;
                }
                else
                {
                    res += romanA[s[i]];
                }
            }
            else
            {
                res += romanA[s[i]];
            }
            ++i;
        }

        return res;
    }

    int romanToInt(std::string s) {
        int res = 0;

        int len=s.length();
        for (int i=0; i<len; i++)
        {
            if (s[i+1]!='\0' && (s[i]=='I'||s[i]=='X'||s[i]=='C'))
            {
                if ((s[i]=='I' && (s[i+1]=='V'||s[i+1]=='X')) ||
                    (s[i]=='X' && (s[i+1]=='L'||s[i+1]=='C')) ||
                    (s[i]=='C' && (s[i+1]=='D'||s[i+1]=='M')))
                {
                    res -= romanA[s[i]];
                }
            }
            else
            {
                res += romanA[s[i]];
            }
        }

        return res;
    }

    int romanToInt_mostvoted(std::string s)
    {
        int res = 0;
        int len = s.length();
        for (int i=0; i<len; i++)
        {
            if (i+1<len && romanA[s[i]]<romanA[s[i+1]])
            {
                res -= romanA[s[i]];
            }
            else
            {
                res += romanA[s[i]];
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    std::cout << "[Please input the data, seperate with space]" << std::endl;
    std::cout << "[like LVIII, all capital letters]" << std::endl;
    std::string line;
	while (std::getline(std::cin, line)) {
        int err_flag = 0;
        int i = 0;
        while (line[i]!='\0')
        {
            if (romanA.find(line[i++])==romanA.end())
            {
                err_flag = 1;
                std::cerr << "Invalid roman number!" << std::endl;
                break;
            }
        }
        if (err_flag)
            continue;
        std::cout << "The input roman number is:"
            << line << std::endl;
        int res = Solution().romanToInt(line);
        std::cout << "The processed result is : "
            << res << std::endl;
    }

    return 0;
}
