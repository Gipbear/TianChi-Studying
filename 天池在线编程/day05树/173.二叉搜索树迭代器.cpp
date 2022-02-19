#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
public:
    vector<int> tree;
    int cur = 0;
    // 中序遍历, 得到一个符合二叉搜索树的顺序
    void dfs(TreeNode *root){
        if(root == nullptr){
            return;
        }
        dfs(root->left);
        tree.push_back(root->val);
        dfs(root->right);
    }

    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        return tree[cur++];
    }
    
    bool hasNext() {
        return cur != tree.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

