#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // 寻找旋转点
        for(int i = 1; i < n; i++){
            if(nums[i-1] > nums[i]){
                // 旋转点前后分别进行二分搜索，较大的结果即为解。
                return max(
                    binSearch(nums, 0, i-1, target),
                    binSearch(nums, i, n-1, target)
                );
            }
        }
        // 完全正序
        return binSearch(nums, 0, n-1, target);
    }
    // 二分搜索
    int binSearch(vector<int>& nums,int left, int right, int target){
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};
// @lc code=end

