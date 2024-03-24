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
    //T.C.=O(n)
    //S.C.=O(1)auxillary space
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* last=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return last;
    }
    void reorderList(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* rev=reverse(slow);
        ListNode* curr=head;
        while(rev->next!=NULL){
            ListNode* tempcurr=curr->next;
            curr->next=rev;
            ListNode* temprev=rev->next;
            rev->next=tempcurr;
            curr=tempcurr;
            rev=temprev;
        }
    }
};

//approach 2
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
    void reorderList(ListNode* head) {
        //T.C.=O(n)
        //S.C.=O(n)
        stack<ListNode*>st;
        ListNode* curr=head;
        while(curr){
            st.push(curr);
            curr=curr->next;
        }
        int k=st.size()/2;
        curr=head;
        while(k--){
            ListNode* topNode=st.top();
            st.pop();
            ListNode* temp=curr->next;
            curr->next=topNode;
            topNode->next=temp;
            curr=temp;
        }
        curr->next=NULL;   //if curr points to itself
    }
};
//approach 3
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
    ListNode* curr;
    void solve(ListNode* head){
        if(head==NULL){
            return;
        }
        solve(head->next);

        ListNode* temp=curr->next;
        if(curr->next==NULL){
            return;
        }
        else if(head==curr){   //if we reach the last node
            head->next=NULL;
            return;
        }
        curr->next=head;
        head->next=(temp==head)?NULL:temp;
        curr=temp;
    }
    void reorderList(ListNode* head) {
        //T.C.=O(n)
        //S.C.=O(1) auxillary space
        curr=head;
        solve(head);
    }
};
