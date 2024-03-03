class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
      //T.C.=O(m*n)
      //S.C.=O(1)
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
      //prefix sum along rows
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                grid[i][j]+=grid[i][j-1];
            }
        }
      //prefix sum along columns
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]+=grid[i-1][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]<=k){
                    count++;
                }
            }
        }
        return count;
    }
};
