class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        //no. of gaps+no. of crosses=size of bricks
        //idea is to minimize the no. of crosses and maximize the no.gaps
        //use the map to store the gaps after every edge in every row
        unordered_map<int,int>mp;
        int crosses=0;
        int Max=0;
        for(int i=0;i<wall.size();i++){
            int gapAtEveryRow=0;
            for(int j=0;j<wall[i].size()-1;j++){  //we have to ignore the last edge case
                gapAtEveryRow+=wall[i][j]; //1,3,5 edges in first iteration
                mp[gapAtEveryRow]++;
                Max=max(Max,mp[gapAtEveryRow]);  //store the maximum no. of gaps
            }
        }
        crosses=wall.size()-Max;
        return crosses;
    }
};
/*
Time Complexity:

    The algorithm traverses each row of the wall once, and for each row, it traverses its bricks once, resulting in a time complexity of O(n⋅m), where nn is the number of rows and mm is the average number of bricks per row.
    In the worst case, iterating through the map to find the maximum frequency also takes O(n⋅m) time.
    Therefore, the overall time complexity is O(n⋅m).

Space Complexity:

    The hash map mp may contain at most n⋅mn⋅m entries, each representing a unique cumulative sum of gaps.
    Hence, the space complexity is O(n⋅m).
*/
