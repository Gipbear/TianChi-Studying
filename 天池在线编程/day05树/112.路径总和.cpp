/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool res = false;  // 标记是否找到路径
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false;
        }
        dfs(root, targetSum);
        return res;
    }

    void dfs(TreeNode *root, int targetSum){
        // 找到就不用再找了
        if(res)
            return;
        // 是叶子结点
        if(root->left == nullptr && root->right == nullptr){
            // 并且刚好符合剩余的target, 则满足
            if(targetSum == root->val)
                res = true;
            return ;
        }
        // 剩余的target减去当前结点的值
        targetSum -= root->val;
        // 遍历左右结点
        if(root->left != nullptr)
            dfs(root->left, targetSum);
        if(root->right != nullptr)
            dfs(root->right, targetSum);
    }
};
// @lc code=end

