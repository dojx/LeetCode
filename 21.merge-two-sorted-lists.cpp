/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
 * iterate through each list 
 * at each step take the smallest value, then move that node to the next
 * if a list has reached the end, merge the other list to the end of res
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *res = new ListNode();
        ListNode *res_tail = res;
        while (list1 != nullptr || list2 != nullptr) {
            // check if list 1 at end
            if (list1 == nullptr) {
                res_tail->next = list2;
                return res->next;
            }
            // check if list 2 at end
            if (list2 == nullptr) {
                res_tail->next = list1;
                return res->next;
            }

            // point res tail to smallest value
            if (list1->val <= list2->val) {
                res_tail->next = list1;
                list1 = list1->next;
            } else {
                res_tail->next = list2;
                list2 = list2->next;
            }
            res_tail = res_tail->next;
        }
        return res->next;
    }
};
// @lc code=end

