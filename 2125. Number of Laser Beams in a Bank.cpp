class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        //T.C.=O(n*m) where mis length of each string
        //S.C=O(1)
        int n=bank.size();
        int prevDeviceCount=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int currentDeviceCount=0;
            for(char &ch:bank[i]){
                if(ch=='1'){
                    currentDeviceCount++;
                }
            }
            ans+=currentDeviceCount*prevDeviceCount;
            if(currentDeviceCount!=0){
                prevDeviceCount=currentDeviceCount;  //important condition
            }
        }
        return ans;
    }
};
