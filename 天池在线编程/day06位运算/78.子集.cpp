#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 使用len表示一共有多少种情况
        int len = 1 << nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < len; i++){
            vector<int> sub;
            // 位上为1的即放入子集中
            for(int j = 0; j < nums.size(); j++){
                if((i>>j) & 1){
                    sub.push_back(nums[j]);
                }
            }
            res.push_back(sub);
        }
        return res;
    }
};
// @lc code=end

