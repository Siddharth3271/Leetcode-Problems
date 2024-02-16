class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        //T.C=O(n)
        //S.C=O(n)
        int n=arr.size();
        unordered_map<int,int>mp;
        for(auto &x:arr){
            mp[x]++;
        }
        vector<int>freqcount(n+1);
        //freqcount[i]=number of elements(types) having frequency i
        int unique=mp.size();
        for(auto &it:mp){
            int freq=it.second;
            freqcount[freq]++;
        }
        for(int freq=1;freq<=n;freq++){
            int types=min(k/freq,freqcount[freq]);
            k=k-types*freq;
            unique-=types;
            if(k<=freq){
            return unique;
            }
        }
        return 0;
    }
};
