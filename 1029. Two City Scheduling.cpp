class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        //T.C.=O(n log n)
        //S.C.=O(1)
        sort(costs.begin(),costs.end(),relativecost);
        int n=costs.size();
        int sum=0;
        for(int i=0;i<n/2;i++){
            sum+=costs[i][0];    //first half
        }
        for(int i=n/2;i<n;i++){
            sum+=costs[i][1];     //second half
        }
        return sum;
    }

    static bool relativecost(vector<int>&first,vector<int> &second){
        return first[1]-first[0]>second[1]-second[0];
    }
};
