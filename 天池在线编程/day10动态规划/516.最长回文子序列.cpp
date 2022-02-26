#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // dp[i][j]代表第i-j个字母之间的最大回文子序列长度
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // dp[i][i]初始化为 1
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        for(int i = n-2; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                // 回文序列两侧相等，则原本的长度+2
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                // 否则使用左右两侧长度较大的代替
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

