class Solution {
public:
    int n,m;
    //T.C.=O(m*n)
    //    The space complexity is also O(m * n).
    //This is because the depth-first search (DFS) algorithm uses recursive calls to traverse the grid. In the worst case, the maximum depth of recursion can be m * n, which corresponds to visiting all cells in the grid.
    void dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>=m || j<0 || j>=n  || grid[i][j]==0){   //water on 0
            return;
        }
        grid[i][j]=0;  //marking visited on all boundary ones(making them zero)

        dfs(grid,i,j+1);   //right
        dfs(grid,i,j-1);   //left
        dfs(grid,i+1,j);   //bottom
        dfs(grid,i-1,j);   //top
    }
    int numEnclaves(vector<vector<int>>& grid) {
        //using dfs
        m=grid.size();
        n=grid[0].size();
        //first col and last col par dfs
        for(int row=0;row<m;row++){
            //first col par dfs
            if(grid[row][0]==1){
                dfs(grid,row,0);
            }

            //last col par dfs
            if(grid[row][n-1]==1){
                dfs(grid,row,n-1);
            }
        }

        //first and last row par dfs
        for(int col=0;col<n;col++){
            //first row par dfs
            if(grid[0][col]==1){
                dfs(grid,0,col);
            }

            //last row par dfs
            if(grid[m-1][col]==1){
                dfs(grid,m-1,col);
            }
        }

        int count=0;
        //count 1's(these are not visited)
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};
