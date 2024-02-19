/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode *temp = res;
        int sum, carry = 0, val;
        while (l1 != nullptr || l2 != nullptr) {
            sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10; 
            val = sum % 10;
            ListNode *new_node = new ListNode(val);
            temp->next = new_node;
            temp = temp->next;
        }
        if (carry) {
            ListNode *new_node = new ListNode(1);
            temp->next = new_node;
        }
        return res->next;
    }
};
// @lc code=end

