class Solution {
public:
    int longestMountain(vector<int>& arr) {
        //T.C.=O(n)
        //S.C.=O(1)
        int n=arr.size();
        int ans=0;
        //0th and n-1th not have peak points
        for(int i=1;i<n-1;){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){   //peak point
                int count=1;   //count th peak point taken already
                int j=i;
                while(j>0 && arr[j]>arr[j-1]){   //left values checking
                    j--;
                    count++;
                }
                while(i<n-1 && arr[i]>arr[i+1]){  //right values checking
                    i++;
                    count++;
                }
                ans=max(count,ans);
            }
            else{
                i++;    //important as we need to keep incrementing if we do not have peak value
            }
        }
        return ans;
    }
};
