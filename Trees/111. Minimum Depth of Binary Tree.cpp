/*the time complexity of the solution is O(n), and the space complexity is O(n), where n is the number of nodes in the binary tree.*/
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
    int minDepth(TreeNode* root) {
        //using bfs(level order traversal)
        if(root==NULL)
            return 0;
        queue<TreeNode*>q;
        q.push(root);
        int depth=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left==NULL && temp->right==NULL){
                    return depth;
                }
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            depth++;   //means 1 level is finished
        }
        return -1;
    }
};


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
    int minDepth(TreeNode* root) {
        //using dfs
        //T.C.=O(n)
        //S.C.=O(n)
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)   //only one node is present
            return 1;
        
        int L=root->left!=NULL ? minDepth(root->left):INT_MAX;
        int R=root->right!=NULL ? minDepth(root->right): INT_MAX;
        
        return 1+min(L,R);
    }
};
