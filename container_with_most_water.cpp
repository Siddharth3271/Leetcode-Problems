class Solution {
public:
    int maxArea(vector<int>& height) {
        //T.C=>O(n)
        //S.C=>O(1)
        int n=height.size();
        int i=0,j=n-1;
        int maxWater=0;
        while(i<j){
            int width=j-i;
            int height1=min(height[i],height[j]);

            int area=height1*width;
            maxWater=max(maxWater,area);
            //moving greedly=> mainly if we reduce the width, try to keep the maximum height for maximum area
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return maxWater;
    }
};
