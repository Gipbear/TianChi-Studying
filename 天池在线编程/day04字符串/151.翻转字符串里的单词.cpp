#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        istringstream str1(s);
        string res, out;
        while(str1 >> out){
            reverse(out.begin(), out.end());
            res += out + ' ';
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end

