#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int m, n;
	bool allIndexMarked(int seconds, vector<int>& changeIndices, vector<int> &nums) {
		//when we have seen the last position of that index
		vector<int>lastPosition(n + 1, -1);
		//T.C.=O(m)
		for (int i = 0; i <= seconds; i++) {
			int idx = changeIndices[i]; //1 based index is present in changeIndices
			lastPosition[idx] = i + 1; //but seconds is one based

		}
		//checking
		//T.C.=O(n)
		for(int i=1;i<=n;i++){
			if(lastPosition[i]==-1){  //index i was not there in the range till seconds
				return false;
			}
		}
		//T.C.=O(nlog n)
		//sorting the elements which appears first to finish it
		map<int,int> positionIndex;  //sorted
		for(int i=1;i<=n;i++){
			int position=lastPosition[i];
			positionIndex[position]=i;
		}
		//T.C.=O(n)
		int time_passed=0;
		for(auto& [position,idx]: positionIndex){
			int required_time=nums[idx-1]+1;  //since we have done zero based indexing
			//decrement to 0+1 second extra for marking
			if(required_time+time_passed>position){
				return false;
			}
			time_passed+=required_time;
		}
		return true;
	}
	int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
		m = changeIndices.size();
		n = nums.size();
		//T.C.=O(m)
		for (int time = 0; time < m; ++time)
		{
			if (allIndexMarked(time, changeIndices, nums)) {
				return time + 1; // since we are doing zero based indexing
			}
		}
		return -1;
		//Total T.C.=>O(m*(m+n+nlogn+n))
		//S.C.=>O(n)
	}
};

//approach 2
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int m, n;
	bool allIndexMarked(int seconds, vector<int>& changeIndices, vector<int> &nums) {
		//when we have seen the last position of that index
		vector<int>lastPosition(n + 1, -1);
		//T.C.=O(m)
		for (int i = 0; i <= seconds; i++) {
			int idx = changeIndices[i]; //1 based index is present in changeIndices
			lastPosition[idx] = i + 1; //but seconds is one based

		}
		//checking
		//T.C.=O(n)
		for(int i=1;i<=n;i++){
			if(lastPosition[i]==-1){  //index i was not there in the range till seconds
				return false;
			}
		}
		//T.C.=O(nlog n)
		//sorting the elements which appears first to finish it
		map<int,int> positionIndex;  //sorted
		for(int i=1;i<=n;i++){
			int position=lastPosition[i];
			positionIndex[position]=i;
		}
		//T.C.=O(n)
		int time_passed=0;
		for(auto& [position,idx]: positionIndex){
			int required_time=nums[idx-1]+1;  //since we have done zero based indexing
			//decrement to 0+1 second extra for marking
			if(required_time+time_passed>position){
				return false;
			}
			time_passed+=required_time;
		}
		return true;
	}
	int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
		m = changeIndices.size();
		n = nums.size();
        int left_time=0,right_time=m-1;
        int result=-1;
        while(left_time<=right_time){
            int mid=left_time+(right_time-left_time)/2;
            if(allIndexMarked(mid,changeIndices,nums)){
                result=mid+1;  //one based indexing
                right_time=mid-1;  //moving left to find even shorter time
            }
            else{
                left_time=mid+1;  //moving right to find greater time to mark all indices
            }
        }
		return result;
		//Total T.C.=>O(log m*(m+n+nlogn+n))
		//S.C.=>O(n)
	}
};
