#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k == 0){
            return false;
        }
        int n = nums.size();
        unordered_map<int, int> num_map;
        for(int i = 0; i < n; i++){
            // 判断该数字是否已经存在
            if(num_map.count(nums[i])){
                // 判断和最后一次出现的距离是否小于等于k
                if(i-num_map[nums[i]] <= k)
                    return true;
            }
            num_map[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end

