class Solution {
public:
    long long calculateArea(vector<int> &r1bottomleft,vector<int> &r1topright,vector<int> &r2bottomleft,vector<int> &r2topright){
        //T.C.=O(n^2)
        //S.C.=O(1)
        long long xBottomleft=max(r1bottomleft[0],r2bottomleft[0]);
        long long yBottomleft=max(r1bottomleft[1],r2bottomleft[1]);
        
        long long xTopright=min(r1topright[0],r2topright[0]);
        long long yTopright=min(r1topright[1],r2topright[1]);

      
        //checking whether forming or not
        if(xTopright>xBottomleft && yTopright>yBottomleft){
            long long side=min(xTopright-xBottomleft,yTopright-yBottomleft);   //taking out square shape
            return side*side;
        }
        return 0;
    }
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long maxArea=0;
        int n=bottomLeft.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxArea=max(maxArea,calculateArea(bottomLeft[i],topRight[i],bottomLeft[j],topRight[j]));
            }
        }
        return maxArea;
    }
};
