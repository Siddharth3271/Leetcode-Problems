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
    TreeNode* add(TreeNode* root,int val, int depth, int curr){
        //T.C.=O(n), where n is the number of nodes in the tree.
        //S.C.= O(d), where d is the depth of the tree.
        if(root==NULL){
            return NULL;
        }
        if(curr==depth-1){
            TreeNode* oldleft=root->left;
            TreeNode* oldright=root->right;
            root->left=new TreeNode(val);
            root->right=new TreeNode(val);

            root->left->left=oldleft;
            root->right->right=oldright;
            return root;
        }
        root->left=add(root->left,val,depth,curr+1);
        root->right=add(root->right,val,depth,curr+1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        int curr=1;
        return add(root,val,depth,curr);
    }
};
