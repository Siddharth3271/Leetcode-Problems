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
    void deleteNode(ListNode* node) {
        ListNode* prev=node;
        while(node!=NULL && node->next!=NULL){
            node->val=node->next->val;
            //update prev
            prev=node;
            node=node->next;
        }
        prev->next=NULL; //since node has reached the last position
        delete(node);
    }
};
