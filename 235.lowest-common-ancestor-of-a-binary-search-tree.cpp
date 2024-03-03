/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;s
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// if left and right paths contain the desired nodes, return the current node

class Solution {
public:
    TreeNode* res;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // helper(root, p, q);
        // return res;
        if (root == p || root == q) return root;
        if (((p->val < root->val) && (q->val > root->val)) || ((p->val > root->val) && (q->val < root->val))) return root;
        TreeNode* res;
        if (p->val < root->val && q->val < root->val) res = lowestCommonAncestor(root->left, p, q);
        else res = lowestCommonAncestor(root->right, p, q);
        return res;
    }

    // bool helper(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if (!root) return false;
    //     // if (root == p || root == q) return true;
    //     bool leftContains = helper(root->left, p, q);
    //     bool rightContains = helper(root->right, p, q);
    //     if (leftContains && rightContains) res = root;
    //     if ((root == p || root == q) && (leftContains || rightContains)) res = root;
    //     if (root == p || root == q) return true;
    //     return leftContains || rightContains;
    // }
};
// @lc code=end

