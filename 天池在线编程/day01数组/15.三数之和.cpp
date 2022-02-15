#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return {};
        }
        // 排序便于去重
        sort(nums.begin(), nums.end());
        // 最小是正数，和一定不可能为0
        if(nums[0] > 0){
            return {};
        }
        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            // l r双指针
            int l = i+1, r = nums.size()-1;
            // 0-第一个元素，就是之前两数之和的target
            int target = -nums[i];
            while(l < r){
                int left = nums[l], right = nums[r];
                int sum = left + right;
                if(sum < target){
                    // 和小于target，左++
                    while(l < r && nums[l] == left) l++;
                }
                else if(sum > target){
                    // 和大于target，右--
                    while(l < r && nums[r] == right) r--;
                }
                else {
                    // 刚好则加入
                    res.push_back({-target, left, right});
                    // 跳过双指针的重复项
                    while(l < r && nums[l] == left) l++;
                    while(l < r && nums[r] == right) r--;
                }
            }
            // 跳过i的重复项
            while(i < n-1 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};
// @lc code=end

