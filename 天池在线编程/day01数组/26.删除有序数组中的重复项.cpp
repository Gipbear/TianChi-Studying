#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        // left 指向目前有序不重复的最后一个下标
        // right 指向大于left的下一个元素
        int left = 0, right = 0;
        while(right < n){
            // 相同则向后遍历
            if(nums[right] == nums[left]){
                right++;
            }
            else{
                // 否则将right对应值赋予在left后
                left++;
                nums[left] = nums[right];
            }
        }
        return left+1;
    }
};
// @lc code=end

