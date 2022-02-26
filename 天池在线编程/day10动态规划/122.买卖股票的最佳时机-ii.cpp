#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[i][0]代表这一天不买股票
        // dp[i][1]代表这一天买股票
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < n; i++){
            // 今天不买，或者卖
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            // 今天不卖，或者买
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return dp[n-1][0];
    }
};
// @lc code=end

