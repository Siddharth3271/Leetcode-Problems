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
    ListNode* removeElements(ListNode* head, int value) {
        // Handle case where head node has the target value
    while (head && head->val == value) {
        ListNode* nextNode = head->next;
        delete head;
        head = nextNode;
    }

    ListNode* temp = head;
    while (temp && temp->next) {
        if (temp->next->val == value) {
            ListNode* nextNode = temp->next->next;
            delete temp->next;
            temp->next = nextNode;
        } else {
            temp = temp->next;
        }
    }
    return head;
    }
};
