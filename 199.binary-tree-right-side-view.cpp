/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<int> actual_res;
        if (root) q.push(root);
        while (q.size()) {
            int sz = q.size();
            vector<int> temp_vec = {};
            actual_res.push_back(q.back()->val);
            for (int i = 0; i < sz; i++) {
                TreeNode* temp = q.front();
                q.pop();
                temp_vec.push_back(temp->val);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            res.push_back(temp_vec);
        }
        // for (vector<int> vec : res) {
        //     actual_res.push_back(vec.back());
        // }
        return actual_res;
    }
};
// @lc code=end

