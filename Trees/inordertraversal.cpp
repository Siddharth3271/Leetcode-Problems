class Solution {
public:
    void inorder(TreeNode* root,vector<int>&ans){
        //T.C.=O(n)
        //S.C.=O(n)
        if(root==NULL)
            return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<int>ans;
        inorder(root,ans);
        return ans;
    }
};

/*The space complexity of the inorderTraversal function is also O(N), where N is the number of nodes in the binary tree. This space is used for the ans vector to store the inorder traversal result. Additionally, the recursive calls consume space on the call stack, but the maximum depth of the call stack is bounded by the height of the binary tree, which is O(N) in the worst case for a skewed tree. Therefore, the overall space complexity is O(N).*/
