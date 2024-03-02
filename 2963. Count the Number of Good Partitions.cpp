class Solution {
public:
    int M=1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
      //T.C.=O(n)  
      //S.C.=O(n) 
      int n=nums.size();
        unordered_map<int,int> last_index;  //store number->last index
        for(int i=0;i<n;i++){
            last_index[nums[i]]=i;
        }
        int res=1;
        int i=0;
        int j=0;
        j=max(j,last_index[nums[0]]);
        while(i<n){
            if(i>j){  //we got a partition
                res=(res*2)%M;
            }
            j=max(j,last_index[nums[i]]); // to store last index value for a partition
            i++;
        }
        return res;
    }
};
