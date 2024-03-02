/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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

/*
 * DFS each node, and store sum of deepest child on left and right
 * store and return a global maximum
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root, 0);
    }

    int helper(TreeNode* root, int globalMax) {
        if (root == nullptr) return 0;
        int left = helper(root->left, globalMax) + 1;
        int right = helper(root->right, globalMax) + 1; 
        return max(globalMax, left + right);
    }
};
// @lc code=end

