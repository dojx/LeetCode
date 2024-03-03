/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    // bool isValidBST(TreeNode* root) {
    //     return helper_l(root->left, root->val) && helper_r(root->right, root->val);
    // }

    // bool helper_l(TreeNode* root, int rootVal) {
    //     if (!root) return true;
    //     if (root->val >= rootVal) return false;
    //     if (root->left && root->val <= root->left->val) return false;
    //     if (root->right && root->val >= root->right->val) return false;
    //     return helper_l(root->left, rootVal) && helper_r(root->right, rootVal);
    // }

    // bool helper_r(TreeNode* root, int rootVal) {
    //     if (!root) return true;
    //     if (root->val <= rootVal) return false;
    //     if (root->left && root->val <= root->left->val) return false;
    //     if (root->right && root->val >= root->right->val) return false;
    //     return helper_l(root->left, rootVal) && helper_r(root->right, rootVal);
    // }

    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

    bool helper(TreeNode* node, long minVal, long maxVal) {
        if (node == nullptr) return true;
        if (node->val <= minVal || node->val >= maxVal) return false;
        return helper(node->left, minVal, node->val) && helper(node->right, node->val, maxVal);
    }
};
// @lc code=end

