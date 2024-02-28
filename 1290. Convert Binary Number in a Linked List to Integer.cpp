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
    int getDecimalValue(ListNode* head) {
        //T.C=O(n)
        //S.C.O(1)
        int count=0;
        ListNode* temp1=head;
        while(temp1){
            count++;
            temp1=temp1->next;
        }
        if(head->next==NULL)
            return head->val;
        ListNode* temp=head;
        int decimal=0;
        while(temp){
            --count;
            decimal+=(temp->val)*pow(2,count);
            temp=temp->next;
        }
        return decimal;
    }
};
