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
    int globalMax = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return globalMax;
    }

    int helper(TreeNode* root) {
        if (root == nullptr) return -1;
        int left = helper(root->left);
        int right = helper(root->right); 
        globalMax = max(globalMax, left + right + 2); 
        return max(left, right) + 1;
    }
};
// @lc code=end

