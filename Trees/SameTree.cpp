class Solution {
public:
//approach 1
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
    {
        return true;
    }
    if(p!=NULL && q==NULL)
    {
        return false;
    }
    if(p==NULL && q!=NULL)
    {
        return false;
    }
    bool left=isSameTree(p->left,q->left);
    bool right=isSameTree(p->right,q->right);
    bool curr=p->val==q->val;
    if(left && right && curr)
    {
        return true;
    }
    else
    {
        return false;
    }
    }
};



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //simple bfs
        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL || q==NULL){
            return false;
        }
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            TreeNode* node1=q1.front(); q1.pop();
            TreeNode* node2=q2.front(); q2.pop();
            if(node1->val !=node2->val){
                return false;
            }
            if(node1->left!=NULL && node2->left!=NULL){
                q1.push(node1->left);
                q2.push(node2->left);
            }
            else if(node1->left!=NULL || node2->left!=NULL){
                return false;
            }
            if(node1->right!=NULL && node2->right!=NULL){
                q1.push(node1->right);
                q2.push(node2->right);
            }
            else if(node1->right!=NULL || node2->right!=NULL){
                return false;
            }
        }
        return true;
    }
};
/*
The time and space complexity of your corrected code is as follows:

Time Complexity:

    The code traverses each node of the binary trees p and q once.
    Therefore, the time complexity is O(n), where n is the total number of nodes in the larger of the two trees.

Space Complexity:

    In the worst case, the queue q1 can contain all the nodes of both trees.
    Therefore, the space complexity is also O(n), where n is the total number of nodes in the larger of the two trees.
*/
