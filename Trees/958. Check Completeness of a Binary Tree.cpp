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
    bool isCompleteTree(TreeNode* root) {
        //using bfs
        //T.C.=O(n)
        //S.C.=O(n)
        queue<TreeNode*>qu;
        qu.push(root);
        bool past=false;   //kya apne past mey null node dekha hai
        while(!qu.empty()){
            TreeNode* node=qu.front();
            qu.pop();
            if(node==NULL){
                past=true;
            }
            else{
                if(past==true){
                    return false;
                }
                else{
                    qu.push(node->left);
                    qu.push(node->right);
                }
            }
        }
        return true;
    }
};
