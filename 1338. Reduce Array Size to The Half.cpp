class Solution {
public:
    int minSetSize(vector<int>& arr) {
        //T.C.=O(n log n)
        //S.C.=O(n)
        map<int,int>mp;
        //by default map orders according to keys in ascending order
        //reverse the ordering->frequency first then key and by descending order
        for(auto it:arr){
            mp[it]++;
        }
        //because frquency may not be unique
        multimap<int,int,greater<int>>mp1;
        for(auto x:mp){
            mp1.insert({x.second,x.first});
        }
        int n=arr.size();
        int sum=n;
        int count=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            sum-=it->first;    //one element and all its occurences are removed
            count++;
            if(sum<=n/2){
                return count;
            }
        }
        return count;
    }
};
