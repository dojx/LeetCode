/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node*, Node*> m;

        // fill hash map
        while (temp != nullptr) {
            Node* new_node = new Node(temp->val);
            m[temp] = new_node;
            temp = temp->next;
        }

        temp = head;
        while(temp != nullptr) {
            m[temp]->next = m[temp->next];
            if (temp->random != nullptr) {
                m[temp]->random = m[temp->random];
            }
            temp = temp->next;
        }

        return m[head];
    }
};
// @lc code=end

