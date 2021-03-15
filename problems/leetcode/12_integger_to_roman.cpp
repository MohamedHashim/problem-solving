/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
#include"bits/stdc++.h"
class Solution
{
public:
    std::string intToRoman(int num)
    {
        std::string res = "";
        std::vector<std::pair<int, std::string>> romans;
        romans.push_back(std::make_pair(1000, "M"));
        romans.push_back(std::make_pair(900, "CM"));
        romans.push_back(std::make_pair(500, "D"));
        romans.push_back(std::make_pair(400, "CD"));
        romans.push_back(std::make_pair(100, "C"));
        romans.push_back(std::make_pair(90, "XC"));
        romans.push_back(std::make_pair(50, "L"));
        romans.push_back(std::make_pair(40, "XL"));
        romans.push_back(std::make_pair(10, "X"));
        romans.push_back(std::make_pair(9, "IX"));
        romans.push_back(std::make_pair(5, "V"));
        romans.push_back(std::make_pair(4, "IV"));
        romans.push_back(std::make_pair(1, "I"));

        for (int i = 0; i < romans.size(); i++)
        {
            if (num == 2)
            {
                res += "II";
                break;
            }
            else if (num == 3)
            {
                res += "III";
                break;
            }
            else if (num % romans[i].first < num)
            {
                int n=0;
                if(num % romans[i].first==0){
                    n= num/romans[i].first;
                    for(int j=0;j<n;j++)
                         res += romans[i].second;
                    break;
                }else{
                res += romans[i].second;
                num = num - romans[i].first;
                i--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
