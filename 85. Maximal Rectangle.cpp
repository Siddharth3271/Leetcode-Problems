class Solution {
public:
    vector<int>getNSR(vector<int> &height){
        stack<int>st;
        int n=height.size();
        vector<int>NSR(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                NSR[i]=n;   //out of bound index
            }
            else{
                while(!st.empty() && height[st.top()]>=height[i]){
                    st.pop();
                }
                if(st.empty()){
                    NSR[i]=n;    //out of bound index
                }
                else{
                    NSR[i]=st.top();
                }
            }
            st.push(i);
        }
        return NSR;
    }
    vector<int>getNSL(vector<int> &height){
        stack<int>st;
        int n=height.size();
        vector<int>NSL(n);
        for(int i=0;i<n;i++){
            if(st.empty()){
                NSL[i]=-1;  //out of bound index
            }
            else{
                while(!st.empty() && height[st.top()]>=height[i]){
                    st.pop();
                }
                if(st.empty()){
                    NSL[i]=-1;    //out of bound index
                }
                else{
                    NSL[i]=st.top();
                }
            }
            st.push(i);
        }
        return NSL;
    }
    int findmaxArea(vector<int> & height){
        //height->height[i]
        //we need to find width in order to calculate maxArea
        //width->NSR[i]-NSL[i]-1

        vector<int>NSR=getNSR(height);
        vector<int>NSL=getNSL(height);
        int n=height.size();
        vector<int>width(n);
        for(int i=0;i<n;i++){
            width[i]=NSR[i]-NSL[i]-1;
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            int a=height[i]*width[i];
            maxArea=max(maxArea,a);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
      //T.C.=O(m*n*n)
      //S.C.=O(n)
        vector<int>height(n);
        //add first row in height as 1-d array
        for(int i=0;i<n;i++){
            height[i]=(matrix[0][i]=='1')?1:0;
        }
        int maxArea=findmaxArea(height);

        for(int row=1;row<m;row++){
            for(int col=0;col<n;col++){
                if(matrix[row][col]=='0'){
                    height[col]=0;
                }
                else{
                    height[col]+=1;
                }
            }
            maxArea=max(maxArea,findmaxArea(height));
        }
        return maxArea;
    }
};
