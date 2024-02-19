/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int sz = 1;
        // find size of list
        while (temp->next != nullptr) {
            sz++;
            temp = temp->next;
        }
        // find n-1th node
        temp = head;
        if (n == sz) return head->next;
        int idx = sz - n - 1;
        while (idx) {
            idx--;
            temp = temp->next;
        }
        // link n-1 to n+1
        if (temp->next != nullptr) temp->next = temp->next->next;
        return head;
    }
};
// @lc code=end

