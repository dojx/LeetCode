/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    // int res = 0;

    int goodNodes(TreeNode* root) {
        return helper(root, root->val);
        // return res;
    }

    int helper(TreeNode* root, int maxValInPath) {
        if (!root) return 0;
        int res = 0;
        if (root->val >= maxValInPath) {
            res++;
            maxValInPath = root->val;
        }
        res += helper(root->left, maxValInPath);
        res += helper(root->right, maxValInPath);
        return res;
    }
};
// @lc code=end

