#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size()-1;
        int left = 0, right = n;
        vector<int> res(n+1);
        while(n >= 0){
            int r = nums[right] * nums[right];
            int l = nums[left] * nums[left];
            if(r > l){
                res[n] = r;
                right--;
            }
            else{
                res[n] = l;
                left++;
            }
            n--;
        }
        return res;
    }
};
// @lc code=end

