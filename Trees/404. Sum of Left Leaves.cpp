//approach 1
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
    int solve(TreeNode* curr,TreeNode* parent){
        if(curr==NULL){
            return 0;
        }
        if(curr->left==NULL && curr->right==NULL){
            //leaf node
            if(parent!=NULL && parent->left==curr){
                return curr->val;
            }
        }
        int left=solve(curr->left,curr);
        int right=solve(curr->right,curr);
        return left+right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        //T.C.=O(n)
        //S.C.=O(1)   Auxillary space
        return solve(root,NULL);
    }
};

//approach 2
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
    int solve(TreeNode* curr,bool isleft){
        if(curr==NULL){
            return 0;
        }
        if(curr->left==NULL && curr->right==NULL && isleft==true){
            //leaf node
            return curr->val;
        }
        return solve(curr->left,true)+solve(curr->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        //T.C.=O(n)
        //S.C.=O(1)   Auxillary space
        return solve(root,false);
    }
};
