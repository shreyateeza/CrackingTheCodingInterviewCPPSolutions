/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode *head) {
        unordered_set<int> visited;
        ListNode *temp = new ListNode(0, head);
        while (temp->next) {
            if (visited.count(temp->next->val)) {
                temp->next = temp->next->next;
            } else {
                visited.insert(temp->next->val);
                temp = temp->next;
            }
        }
        return head;
    }
};