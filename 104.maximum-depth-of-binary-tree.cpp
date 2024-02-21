/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        // DFS
        // return helper(root);

        // BFS
        int res = 0;
        queue<TreeNode*> q;
        if (root != nullptr) q.push(root);
        while (q.size()) {
            ++res;
            int sz = q.size();
            // go through all nodes at current depth
            for (int i = 0; i < sz; i++) {
                TreeNode* front = q.front();
                q.pop();
                if (front->left != nullptr) q.push(front->left);
                if (front->right != nullptr) q.push(front->right);
            }
        }

        return res;
    }

    int helper(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(helper(root->left) + 1, helper(root->right) + 1);
    }
};
// @lc code=end

