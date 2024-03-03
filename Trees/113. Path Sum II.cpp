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
    vector<vector<int>>ans;
    void fill(TreeNode* root,int sum,vector<int>temp,int targetSum){
        if(root==NULL)
            return;
        sum+=root->val;
        temp.push_back(root->val);
        //if it is a leaf node
        if(root->left ==NULL && root->right==NULL){
            if(sum==targetSum){
                ans.push_back(temp);
            }
            return;
        }
        fill(root->left,sum,temp,targetSum);
        fill(root->right,sum,temp,targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int>temp;
        fill(root,sum,temp,targetSum);
        return ans;
    }
};

/*
Time Complexity:

    The time complexity mainly depends on the number of nodes in the binary tree and the number of valid paths found.
    In the worst case, if all paths from the root to the leaves need to be traversed, the time complexity would be O(n), where n is the number of nodes in the tree.

Space Complexity:

    The space complexity is determined by the space used for storing the result paths and the recursive call stack.
    The space used to store the result paths is O(p * h), where p is the number of valid paths and h is the height of the binary tree. This is because each path can have at most h nodes.
    The recursive call stack can go as deep as the height of the binary tree, resulting in O(h) space complexity.
    Therefore, the overall space complexity is O(p * h + h), which simplifies to O(p * h), where p is the number of valid paths and h is the height of the binary tree.
*/
