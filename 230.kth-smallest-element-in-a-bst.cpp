/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    // int res;
    // int count;

    // int kthSmallest(TreeNode* root, int k) {
    //     count = k;
    //     helper(root);
    //     return res;
    // }

    // void helper(TreeNode* root) {
    //     if (!root) return;
    //     helper(root->left);
    //     if (count == 0) return;
    //     res = root->val;
    //     count--;
    //     helper(root->right);
    // }
    int kthSmallest(TreeNode* root, int k) {
        return helper(root, k);
    }

private:
    int helper(TreeNode*& root, int& k) {
        if (root) {
            int x = helper(root->left, k);
            if (k == 0) return x;
            if (--k == 0) return root->val;
            return helper(root->right, k);
        }
        return -1; // Arbitrary value, will never be used.
    }
};
// @lc code=end

