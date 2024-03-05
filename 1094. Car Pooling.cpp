class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //T.C.=O(n log n)
        //S.C.=O(n)
        map<int,int>mp;
        for(vector<int>v:trips){
            int start=v[1];
            int end=v[2];
            mp[start]+=v[0];   //at starting how many passengers are in car
            mp[end]-=v[0];     //how many left at that point
        }
        int sum=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            sum+=it->second;
            if(sum>capacity) return false;
        }
        return true;
    }
};
