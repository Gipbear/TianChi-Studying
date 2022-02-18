#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s, int left, int right){
        while(left < right){
            if(s[left] != s[right])
                return false;
            left++; right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int error = 1;
        int left = 0, right = s.size()-1;
        while(left < right){
            if(s[left] != s[right]){
                return isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1);
            }
            left++; right--;
        }
        return true;
    }
};
// @lc code=end

