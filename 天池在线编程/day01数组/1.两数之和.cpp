#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            int sub = target - nums[i];
            for(int j = i+1; j < n; j++){
                if(nums[j] == sub)
                    return {i, j};
            }
        }
        return {-1,-1};
    }
};
// @lc code=end

