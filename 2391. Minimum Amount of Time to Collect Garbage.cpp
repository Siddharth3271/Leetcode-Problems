class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        //T.C.=O(n*10)=O(n)
        //S.C.=O(1)
        int time=0;
        int n=garbage.size();
        int g_idx=0;
        int p_idx=0;
        int m_idx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<garbage[i].length();j++){
                if(garbage[i][j]=='M'){
                    m_idx=i;  //finding the last position
                }
                else if(garbage[i][j]=='P'){
                    p_idx=i;     //finding the last position
                }
                else{
                    g_idx=i;     //finding the last position
                }
                time++;
            }
        }

        for(int i=1;i<travel.size();i++){
            travel[i]+=travel[i-1];        //finding prefix sum of the time
        }


        time+=  m_idx>0? travel[m_idx-1]:0;   //time taken to travel house for M truck
        time+=  p_idx>0? travel[p_idx-1]:0;  //time taken to travel house for P truck
        time+=  g_idx>0? travel[g_idx-1]:0;  //time taken to travel house for G truck

        return time;
    }
};
