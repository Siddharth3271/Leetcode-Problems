class Solution {
public:
    //T.C.=O(n^2)
    //S.C.=O(n)
    void rotate(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=m;
        //First find Transpose
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        //then reverse rows of matrix
        for(int i=0;i<m;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }
};
