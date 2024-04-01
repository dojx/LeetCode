/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */

// @lc code=start
#include <iterator>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size() || !inorder.size()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        int inorderRootIndex = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == preorder[0]) {
                inorderRootIndex = i;
                break;
            }
        }
        vector<int> preorderLeftSublist(preorder.begin() + 1, preorder.begin() + inorderRootIndex + 1);
        vector<int> inorderLeftSublist(inorder.begin(), inorder.begin() + inorderRootIndex);
        root->left = buildTree(preorderLeftSublist, inorderLeftSublist);
        
        vector<int> preorderRightSublist(preorder.begin() + inorderRootIndex + 1, preorder.end());
        vector<int> inorderRightSublist(inorder.begin() + inorderRootIndex + 1, inorder.end());
        root->right = buildTree(preorderRightSublist, inorderRightSublist);
        
        return root; 
    }
};
// @lc code=end

