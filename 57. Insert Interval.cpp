//approach 1
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        //T.C.=O(n^2)
        //S.C.=O(1)
        while(i<intervals.size()){   //since size changes when we delete  O(n)
            if(intervals[i][1]<newInterval[0]){
                i++;
            }else if(intervals[i][0]>newInterval[1]){
                intervals.insert(intervals.begin()+i,newInterval);  //shifting O(n)
                return intervals;
            }
            else{
                //overlap
                //merge them and erase the intervals which was merged
                newInterval[0]=min(newInterval[0],intervals[i][0]);   //start point
                newInterval[1]=max(newInterval[1],intervals[i][1]);   //end point
                intervals.erase(intervals.begin()+i);  //shifting left side O(n)
            }
        }
        intervals.push_back(newInterval);  //when the insertion is larger than all intervals
        return intervals;
    }
};

//approach 2
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //T.C.=O(n)
        //S.C.=O(n)
        int i=0;
        vector<vector<int>>res;
        int n=intervals.size();
        while(i<n){
            if(intervals[i][1]<newInterval[0]){
                res.push_back(intervals[i]);
            }
            else if(intervals[i][0]>newInterval[1]){
                break;
            }
            else{
                //merge kardo
                newInterval[0]=min(newInterval[0],intervals[i][0]);  //start point
                newInterval[1]=max(newInterval[1],intervals[i][1]);  //end point
            }
            i++;
        }
        res.push_back(newInterval);
        while(i<n){
            res.push_back(intervals[i]);  //bache kuche ko daal do
            i++;
        }
        return res;
    }
};
