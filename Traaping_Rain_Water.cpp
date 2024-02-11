class Solution {
public:
    vector<int>getleftMax(vector<int> &height,int& n){
        vector<int>leftMax(n);
        leftMax[0]=height[0];
        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],height[i]);
        }
        return leftMax;
    }
    vector<int>getrightMax(vector<int> &height,int& n){
        vector<int>rightMax(n);
        rightMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i]);
        }
        return rightMax;
    }
    int trap(vector<int>& height) {
        //by array
        int n=height.size();
        vector<int>leftMax=getleftMax(height,n);
        vector<int>rightMax=getrightMax(height,n);
        int sum=0;
        for(int i=0;i<n;i++){
            int h=min(leftMax[i],rightMax[i])-height[i];
            sum+=h; 
        }
        return sum;
    }
};
/*
    Time Complexity:
        The getleftMax and getrightMax functions iterate over the height array once to calculate the left and right maximum heights for each position, respectively. Each of these functions has a time complexity of O(n), where n is the size of the height array.
        The main trap function iterates over the height array once more to calculate the amount of trapped water. This loop also has a time complexity of O(n).
        Therefore, the overall time complexity of the solution is O(n), where n is the size of the input height array.

    Space Complexity:
        The additional space used in the solution is mainly for storing the leftMax and rightMax arrays, each of size n, where n is the size of the input height array. Therefore, the space complexity of these arrays is O(n).
        Additionally, there are some auxiliary variables used in the functions, but they require constant space compared to the size of the input array.
        Hence, the overall space complexity of the solution is O(n).
*/
