#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode* build(vector<int>& inorder, int inlow, int inhigh, vector<int>& postorder, int poststart, int postend){
        if(poststart > postend){
            return nullptr;
        }
        int mid = inlow;
        for(int i = inlow; i <= inhigh; i++){
            if(inorder[i] == postorder[postend]){
                mid = i;
                break;
            }
        }
        int width = mid - inlow;
        TreeNode *node = new TreeNode(postorder[postend]);
        node->left = build(inorder, inlow, inlow+width, postorder, poststart, poststart+width-1);
        node->right = build(inorder, inlow+width+1, inhigh, postorder, poststart+width, postend-1);
        return node;
    }
};
// @lc code=end

