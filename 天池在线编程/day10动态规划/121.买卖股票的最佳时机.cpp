#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = INT_MAX, maxProf = 0;
        for(int p : prices){
            maxProf = max(p-minPrice, maxProf);
            minPrice = min(minPrice, p);
        }
        return maxProf;
    }
};
// @lc code=end

