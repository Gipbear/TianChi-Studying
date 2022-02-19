#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return dfs(root);
    }

    int dfs(TreeNode *root){
        // base case 该结点为叶子结点
        if(root->left == nullptr && root->right == nullptr)
            return 1;
        // 左右结点初始化为最大值
        int left = INT_MAX, right = INT_MAX;
        // 计算左结点的深度
        if(root->left != nullptr){
            left = dfs(root->left);
        }
        // 计算右结点的深度
        if(root->right != nullptr){
            right = dfs(root->right);
        }
        // 取两侧的最小值
        return min(left, right)+1;
    }
};
// @lc code=end

