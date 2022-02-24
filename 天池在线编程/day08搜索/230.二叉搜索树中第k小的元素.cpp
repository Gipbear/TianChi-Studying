#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int res = -1, cnt = -1;
    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        dfs(root);
        return res;
    }
    void dfs(TreeNode * root){
        if(root == nullptr || cnt == 0){
            return ;
        }
        dfs(root->left);
        cnt--;
        if(cnt == 0){
            res = root->val;
            return ;
        }
        dfs(root->right);
    }
};
// @lc code=end

