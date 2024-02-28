class Solution {
public:
    void preorder(TreeNode* root,vector<int>&ans){
        //T.C.=O(n)
        //S.C.=O(n)
        if(root==NULL)
            return;
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<int>ans;
        preorder(root,ans);
        return ans;
    }
};
