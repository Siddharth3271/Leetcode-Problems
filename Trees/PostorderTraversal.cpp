class Solution {
public:
    void postorder(TreeNode* root,vector<int>&ans){
        //T.C.=O(n)
        //S.C.=O(n)
        if(root==NULL)
            return;
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<int>ans;
        postorder(root,ans);
        return ans;
    }
};
