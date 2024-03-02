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
    ListNode* partition(ListNode* head, int x) {
        //T.C.=O(n)
      //S.C.=O(1)
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* small=new ListNode(0);
        ListNode* large=new ListNode(0);
        ListNode* sp=small;
        ListNode* lg=large;
        while(head!=NULL){
            if(head->val<x){
                sp->next=head;
                sp=sp->next;
            }
            else{
                lg->next=head;
                lg=lg->next;
            }
            head=head->next;
        }
        
        sp->next=large->next;
        lg->next=NULL;
        return small->next;
    }
};
