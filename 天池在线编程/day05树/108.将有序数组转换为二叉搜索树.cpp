#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        return binarySearch(nums, left, right);
    }

    TreeNode* binarySearch(vector<int> & nums, int left, int right){
        // base case
        if(left > right){
            return nullptr;
        }
        // 计算端点的中点作为中间结点
        int mid = left + (right-left)/2;
        TreeNode *res = new TreeNode(nums[mid]);
        // 左右两侧区间的中间结点作为其叶子节点
        res->left = binarySearch(nums, left, mid-1);
        res->right = binarySearch(nums, mid+1, right);
        return res;
    }
};
// @lc code=end

