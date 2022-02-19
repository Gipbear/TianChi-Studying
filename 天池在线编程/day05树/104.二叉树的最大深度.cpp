#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }

    int dfs(TreeNode *root){
        // base case 该结点为空
        if(root == nullptr)
            return 0;
        // 非空的话就返回该结点的左右结点中较长的深度, 并+1
        return max(dfs(root->left), dfs(root->right))+1;
    }
};
// @lc code=end

