/*
Time Complexity:

    Initialization: Initializing the start_time and end_time vectors takes O(m) time, where m is the number of flowers.
    Sorting: Sorting the start_time and end_time vectors takes O(m log m) time each.
    Processing Queries: For each person, the algorithm performs binary search operations:
        The upper_bound operation takes O(log m) time to find the index of the first bloomed flower after the person's query time.
        The lower_bound operation also takes O(log m) time to find the index of the first flower that died on or after the person's query time.
        Since there are n query times (where n is the number of people), the overall time complexity for processing queries is O(n log m).
    Therefore, the overall time complexity of the algorithm is dominated by the sorting and query processing steps, resulting in O(m log m + n log m).

Space Complexity:

    The space complexity is determined by the storage of vectors start_time, end_time, and result, each of size m or n.
    Therefore, the space complexity is O(m + n), where m is the number of flowers and n is the number of people.
*/

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
       int m=flowers.size();
       int n=people.size();
       vector<int>start_time(m); 
       vector<int>end_time(m);
       vector<int>result(n);
       for(int i=0;i<m;i++){
           start_time[i]=flowers[i][0];
           end_time[i]=flowers[i][1];
       }
       sort(start_time.begin(),start_time.end()); 
       sort(end_time.begin(),end_time.end()); 
       for(int i=0;i<n;i++){
           int time=people[i];
           int bloomed_already=upper_bound(start_time.begin(),start_time.end(),time)-start_time.begin();  //get first element index which is greater than this time
           int died_already=lower_bound(end_time.begin(),end_time.end(),time)-end_time.begin();  // get first element index which is greater or equal to this time
           result[i]=bloomed_already-died_already;
       }
       return result;
    }
};
