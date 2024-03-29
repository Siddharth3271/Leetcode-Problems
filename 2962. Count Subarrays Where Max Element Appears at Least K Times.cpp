//approach 1
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        //T.C.=O(2*n)
        //S.C.=O(1)
        int maxE=*max_element(nums.begin(),nums.end());
        int i=0,j=0;
        long long res=0;
        int countMAX=0;
        while(j<n){
            if(maxE==nums[j]){
                countMAX++;
            }
            while(countMAX>=k){  //it ensures that we are counting all subarrays
                res+=n-j;
                if(nums[i]==maxE){
                    countMAX--;
                }
                i++;
            }
            j++;
        }
        return res;
    }
};
//approach 2
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        //T.C.=O(2*n)
        //S.C.=O(n)
        int maxE=*max_element(nums.begin(),nums.end());
        int i=0,j=0;
        long long res=0;
        vector<int>maxindex;
        for(int i=0;i<n;i++){
            if(maxE==nums[i]){
                maxindex.push_back(i);
            }
            int size=maxindex.size();
            if(size>=k){
                int last=maxindex[size-k];
                res+=last+1;
            }
        }
        return res;
    }
};
