/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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

/*
 * 1. start curr at head node of current list, store next node in temp
 * 2. find tail node in current list, point curr->next to that node
 * 3. then equal curr to temp, and tail->next to curr
 * 4. repeat steps 1-3, until temp->next == nullptr or temp->next == tail
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *curr = head, *temp, *tail;
        temp = curr->next;
        tail = curr;

        while (temp->next != nullptr) {
            // find tail of current list
            while (tail->next->next != nullptr) {
                tail = tail->next->next;
            }
            curr->next = tail;
            curr = temp;
            tail->next = curr;
            tail = curr;
            temp = curr->next;
        }
    }
};
// @lc code=end

