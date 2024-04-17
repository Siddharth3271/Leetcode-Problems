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
//by dfs
class Solution {
public:
    string result="";
    void dfs(TreeNode* root,string curr){
        if(root==NULL){
            return;
        }
        curr=char(root->val+'a')+curr;   //O(length of curr)
        if(root->left==NULL && root->right==NULL){
            if(result==""|| result>curr){
                result=curr;
            }
        }
        dfs(root->right,curr);
        dfs(root->left,curr);
    }
    string smallestFromLeaf(TreeNode* root) {
        //T.C.=O(n^2)  where n is no. of nodes
        //S.C.=O(n) where n is height of tree
        dfs(root,"");
        return result;
    }
};


//using bfs
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
    string result="";
    string smallestFromLeaf(TreeNode* root) {
        //T.C.=O(n^2)  where n is no. of nodes
        //S.C.=O(n*h) where h is height of tree and n/2 nodes of queue
        queue<pair<TreeNode*,string>>qu;
        qu.push({root,string(1,char(root->val+'a'))});
        while(!qu.empty()){
            auto[node,curr]=qu.front();
            qu.pop();
            if(node->left==NULL && node->right==NULL){
                if(result==""|| result>curr){
                    result=curr;
                }
            }
            if(node->left){
                qu.push({node->left,char(node->left->val+'a')+curr});
            }
            if(node->right){
                qu.push({node->right,char(node->right->val+'a')+curr});
            }
        }
        return result;
    }
};
