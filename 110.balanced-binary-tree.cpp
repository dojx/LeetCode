/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool is_balanced = true;

    bool isBalanced(TreeNode* root) {
        helper(root);
        return is_balanced;
    }

    int helper(TreeNode* root) {
        if (!root) return -1;
        int left = helper(root->left);
        int right = helper(root->right);
        if (abs(left - right) > 1) is_balanced = false;
        return max(left, right) + 1;
    }
};
// @lc code=end

