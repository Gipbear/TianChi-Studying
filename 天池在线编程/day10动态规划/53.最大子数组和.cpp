#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        for(int i = 0; i < n; i++){
            dp[i+1] = max(dp[i]+nums[i], nums[i]);
        }
        int maxNum = INT_MIN;
        for(int i = 1; i <= n; i++){
            maxNum = max(maxNum, dp[i]);
        }
        return maxNum;
    }
};
// @lc code=end

