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
        ListNode *slow, *fast;
        slow = fast = head;

        // find mid point
        while (fast->next != nullptr) {
            slow = slow->next;
            if (fast->next->next == nullptr) break;
            fast = fast->next->next;
        }

        // reverse second list
        ListNode *prev = nullptr;
        while (slow != nullptr) {
            fast = slow->next;
            slow->next = prev;
            prev = slow;
            slow = fast;
        }

        // merge two lists
        ListNode *temp;
        fast = head;
        slow = prev;
        while (fast != nullptr && slow != nullptr) {
            temp = fast->next;
            fast->next = slow;
            fast = slow;
            slow = temp;
        }

        // If there are remaining nodes in either list, append them to the end
        if (fast != nullptr) {
            fast->next = slow;
        }
    }
};
// @lc code=end

// O(n^2) solution
// void reorderList(ListNode* head) {
//         ListNode *curr, *next, *tail, *temp;
//         curr = head;

//         while (curr->next != nullptr && curr->next->next != nullptr) {
//             next = curr->next;
//             tail = curr;
//             while (tail->next->next != nullptr) {
//                 tail = tail->next;
//             }
//             temp = tail->next;
//             tail->next = nullptr;
//             curr->next = temp;
//             temp->next = next;
//             curr = next;
//         }
//     }