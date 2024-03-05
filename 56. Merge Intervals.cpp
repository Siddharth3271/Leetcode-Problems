class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        for(int i=0;i<intervals.size();i++){
            if(res.empty()){     //there are no intervals to compare
                res.push_back(intervals[i]);
            }
            else{
                vector<int>&v=res.back();
                int y1=v[1];   //end part of previous interval
                //compare it with current interval start part
                //[1,6] [2,5] -->  [1,5]
                //[1,5] [2,6] -->  [1,6]
                if(intervals[i][0]<=y1){    //case of overlap
                    v[1]=max(y1,intervals[i][1]);
                }
                else{
                    res.push_back(intervals[i]);    //not overlap
                }
            }
        }
        return res;
    }
};
