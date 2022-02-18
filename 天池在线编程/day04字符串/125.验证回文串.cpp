#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left < right){
            while(left < right && !isalnum(s[left])){
                left++;
            }
            while(left < right && !isalnum(s[right])){
                right--;
            }
            if(s[left] == s[right] || s[left] == (s[right]^32)){
                left++; right--;
                continue;
            }
            else{
                left++; right--;
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

