#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = nums[0]+nums[1]+nums[2];
        for(int i = 0; i < n-2; i++){
            int left = i+1, right = n-1;
            while(left < right){
                int subTarget = nums[i] + nums[left] + nums[right];
                if(abs(target-subTarget) < abs(target-res)){
                    res = subTarget;
                }
                if(subTarget > target)
                    right--;
                else if(subTarget < target)
                    left++;
                else
                    return res;
            }
        }
        return res;
    }
};
// @lc code=end

