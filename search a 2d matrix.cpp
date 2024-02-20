class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //T.C=O(log(m*n))
        //S.C=O(1)
        int m=matrix.size();
        int n=matrix[0].size();
        int start=0,end=m*n-1; //converting 2d to 1d index
        while(start<=end){
            int mid=start+(end-start)/2;
            if(matrix[mid/n][mid%n]>target){//trick for 1d to 2d index
                
                end=mid-1;
            }
            else if(matrix[mid/n][mid%n]<target){
                start=mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
