class Solution {
public:
    static bool comp(pair<int,int>p1,pair<int,int>p2){
        return p1.second>p2.second;
    }
    //T.C.=O(n log n)
    //S.C.=O(n)
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        //sort according to the growtime
        //first give time to that plant which takes maximum time to grow so that it gets sufficient time to grow
        //this is the limiting factor
        vector<pair<int,int>>v;
        for(int i=0;i<plantTime.size();i++){
            v.push_back({plantTime[i],growTime[i]});
        }
        sort(v.begin(),v.end(),comp);
        int start=0;
        int ans=0;  //maximum no. of days needed
        for(int i=0;i<plantTime.size();i++){
            start+=v[i].first;
            ans=max(ans,start+v[i].second);
        }
        return ans;
    }
};
