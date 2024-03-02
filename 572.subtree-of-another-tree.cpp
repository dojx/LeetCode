/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // BFS
        // queue<TreeNode*> q;
        // q.push(root);
        // while (q.size()) {
        //     TreeNode* temp = q.front();
        //     q.pop();
        //     if (temp->val == subRoot->val) {
        //         if (isSameTree(temp, subRoot)) return true;
        //     }
        //     if (temp->left) q.push(temp->left);
        //     if (temp->right) q.push(temp->right);
        // }
        // return false;

        // DFS
        if (!subRoot) return true;
        if (!root) return false;
        if (isSameTree(root, subRoot)) return true;
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};
// @lc code=end

