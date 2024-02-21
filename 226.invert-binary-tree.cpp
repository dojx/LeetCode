/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    TreeNode* invertTree(TreeNode* root) {
        // BFS
        // if (root == nullptr) return root;

        // TreeNode* temp = root->left;
        // root->left = root->right;
        // root->right = temp;

        // invertTree(root->left);
        // invertTree(root->right);

        // return root;

        // DFS
        queue<TreeNode*> q;
        TreeNode* curr;
        if (root != nullptr) q.push(root);
        while(q.size()) {
            curr = q.front();
            q.pop();
            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }

        return root;
    }
};
// @lc code=end

