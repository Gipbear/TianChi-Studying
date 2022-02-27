#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int cnt = 1;
        for(int i = 1; i < nums.size(); i++){
            if(cnt == 0){
                res = nums[i];
                cnt++;
            } 
            else if(nums[i] != res)
                cnt--;
            else{
                cnt++;
            }
        }
        return res;
    }
};
// @lc code=end

