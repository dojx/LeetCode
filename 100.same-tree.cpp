/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // BFS
        // queue<TreeNode*> q1, q2;
        // TreeNode *curr_p = p, *curr_q = q;
        // q1.push(p);
        // q2.push(q);
        
        // while(q1.size() && q2.size()) {
        //     curr_p = q1.front();
        //     q1.pop();
        //     curr_q = q2.front();
        //     q2.pop();
        //     if (curr_p == curr_q) continue;
        //     if (!curr_p || !curr_q) return false;
        //     if (curr_p->val != curr_q->val) return false;
        //     if (curr_p) {
        //         q1.push(curr_p->left);
        //         q1.push(curr_p->right);
        //     }
        //     if (curr_q) {
        //         q2.push(curr_q->left);
        //         q2.push(curr_q->right);
        //     }
        // }

        // return true;

        // DFS
        if (p == q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};
// @lc code=end

