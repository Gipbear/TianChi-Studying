#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m+n-1; i >= 0; i--){
            if(m == 0 || n == 0)
                break;
            // 较大的数放后面
            if(nums2[n-1] > nums1[m-1]){
                nums1[i] = nums2[n-1];
                n--;
            }
            else{
                nums1[i] = nums1[m-1];
                m--;
            }
        }
        // 剩下的nums2全部放前面
        while(n){
            nums1[n-1] = nums2[n-1];
            n--;
        }
    }
};
// @lc code=end

