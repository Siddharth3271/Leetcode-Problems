class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        //T.C.=O(n log n)
        //S.C.=O(n)
        sort(points.begin(),points.end());  //by default by starting point
        vector<int>prev=points[0];   //depects previous points
        int count=1;   //one arrow at least needed for points[0]
        for(int i=1;i<n;i++){
            int currStartPoint=points[i][0];
            int currEndPoint=points[i][1];
            int prevStartPoint=prev[0];
            int prevEndPoint=prev[1];
            if(currStartPoint>prevEndPoint){   //no overlap
                count++;
                prev=points[i];
            }
            else{   //pakka overlap hai
                //overlapping region nikal lo
                prev[0]=max(prevStartPoint,currStartPoint);
                prev[1]=min(currEndPoint,prevEndPoint);
            }
        }
        return count;
    }
};
