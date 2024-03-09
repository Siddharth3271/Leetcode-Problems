class Solution {
public:
    //bottom-up
    //T.C.=O(n^2)
    //S.C.=O(n^2)
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<long long>>t(501,vector<long long>(501,INT_MIN));
        //t[i][j]==> max value till 0....i food and time is j currently
        //at time 0 we have no value ,i.e 0 as cooking has not yet started
        for(int i=0;i<501;i++){
            t[i][0]=0;  //fill first column with zero
        }
        //cooking started at time=1 sec
        t[0][1]=satisfaction[0]*1;
        for(int i=1;i<n;i++){
            for(int time=1;time<=n;time++){
                long long include=satisfaction[i]*time+t[i-1][time-1];
                long long exclude=t[i-1][time];  //since time always increases
                t[i][time]=max(include,exclude);
            }
        }
        //since the question doesn't ask about value at time =n
        //but it asks for maximum value overall at any time
        //so we check for the values for all time food 0....n-1, i.e. last row depicts 0....n-1 t[n-1]
        long long ans=0;
        for(int time=0;time<=n;time++){
            ans=max(ans,t[n-1][time]);
        }
        return ans;
    }
};


class Solution {
public:
    //memoization
    //T.C.=O(n^2)
    //S.C.=O(n^2)
    int n;
    int t[501][501];
    int solve(vector<int>& satisfaction,int index,int time){
        if(index>=n){
            return 0;
        }
        if(t[index][time]!=-1){
            return t[index][time];
        }
        int include=satisfaction[index]*time+solve(satisfaction,index+1,time+1);
        int exclude=solve(satisfaction,index+1,time);
        return t[index][time]=max(include,exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        n=satisfaction.size();
        memset(t,-1,sizeof(t));
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction,0,1);    //solve(satisfaction,starting index,starting time)
    }
};
