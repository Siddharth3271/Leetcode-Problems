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
    ListNode* swapNodes(ListNode* head, int k) {
        //approach 1
        //kth node from start
        //kth node from end
        int count=0;
        ListNode* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        int k1=k;
        int k2=count-k+1;
        ListNode* node1=head;
        ListNode* node2=head;
        while(k1>1){
            node1=node1->next;
            k1--;
        }
        while(k2>1){
            node2=node2->next;
            k2--;
        }
        swap(node1->val,node2->val);
        return head;
    }
};



class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        //2nd approach
        //single loop(single pass)
        ListNode* temp=head;
        ListNode* p1=NULL;
        ListNode* p2=NULL;
        while(temp){
            if(p2!=NULL){
                p2=p2->next;
            }
            k--;
            if(k==0){
                p1=temp;  //p1 work is finished
                p2=head;  //activate p2
            }
            
            temp=temp->next;
        }
        swap(p1->val,p2->val);
        return head;
    }
};
