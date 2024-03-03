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
    int solve(TreeNode* root,int curr){
        if(root==NULL){
            return 0;
        }
        curr=curr*10+(root->val);
        
        //we have found the root to leaf part
        if(root->left==NULL && root->right==NULL){
            return curr;
        }
        int l=solve(root->left,curr);
        int r=solve(root->right,curr);
        return l+r;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};
/*
The time and space complexity of the provided solution are as follows:

    Time Complexity (T.C.):
        In the solve function, each node of the binary tree is visited exactly once.
        Therefore, the time complexity of the solve function is O(n), where n is the number of nodes in the binary tree.
        Since each operation inside the solve function (such as addition and multiplication) takes constant time, the overall time complexity of the sumNumbers function is also O(n).

    Space Complexity (S.C.):
        The space complexity of the solution is determined by the space used by the recursive call stack.
        In the worst case scenario, the recursive depth of the solve function could be equal to the height of the binary tree.
        Therefore, the space complexity of the recursive call stack is O(h), where h is the height of the binary tree.
        Additionally, no additional data structures are used that scale with the input size, so they do not contribute significantly to the space complexity.
        Hence, the overall space complexity is O(h), where h is the height of the binary tree.
*/
