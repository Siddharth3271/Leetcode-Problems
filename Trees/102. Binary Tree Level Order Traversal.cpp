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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        //T.C.=O(n)
        //S.C.=O(n)
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>SingleLevel;
            int size=q.size(); //for traversal at each level
            for(int i=0;i<size;i++){
                TreeNode* newNode=q.front();
                q.pop();
                if(newNode->left!=NULL)
                    q.push(newNode->left);
                if(newNode->right!=NULL)
                    q.push(newNode->right);
                SingleLevel.push_back(newNode->val);
            }
            res.push_back(SingleLevel);
        }
        return res;
    }
};
