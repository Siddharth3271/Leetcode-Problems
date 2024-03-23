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
//approach 1
//T.C.=O(n)
//S.C.=O(1) but recursion space is used
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* last=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return last;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        while(fast && fast->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        ListNode* tail=reverse(slow);
        prev->next=NULL;
        while(tail!=NULL && head!=NULL){
            if(head->val!=tail->val){
                return false;
            }
            head=head->next;
            tail=tail->next;
        }
        return true;
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
//approach 1
//T.C.=O(n)
//S.C.=O(1) but recursion space is used
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* last=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return last;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        while(fast && fast->next){
            fast=fast->next->next;
            ListNode* temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        //if linked list length is odd
        if(fast){
            slow=slow->next;
        }
        while(prev && slow){
            if(prev->val!=slow->val){
                return false;
            }
            prev=prev->next;
            slow=slow->next;
        }
        return true;
    }
};

//approach 3
//T.C.=O(n)
//S.C.=O(1) auxillary space
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
    bool recur(ListNode* head){
        if(head==NULL){
            return true;
        }
        bool ans=recur(head->next);
        if(head->val!=curr->val){
            return false;
        }
        curr=curr->next;
        return ans;
    }
    bool isPalindrome(ListNode* head) {
        curr=head;
        return recur(head);
    }
};
