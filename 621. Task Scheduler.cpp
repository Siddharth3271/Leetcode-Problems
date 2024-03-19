class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //T.C.=O(n)  
        //S.C.=O(1)  only 26 size
        vector<int>freq(26,0);
        for(char &ch:tasks){
            freq[ch-'A']++;
        }
        int time=0;
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push(freq[i]);
            }
        }

        while(!pq.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){ //only n+1 tasks at a time because after doing 1 task we have to wait for n time
                if(!pq.empty()){
                    int f=pq.top();
                    pq.pop();
                    f--;
                    temp.push_back(f);
                }
            }
            for(int &f:temp){
                if(f>0){
                    pq.push(f);
                }
            }
            if(pq.empty()){
                time+=temp.size();
            }
            else{
                time+=n+1;
            }
        }
        return time;
    }
};
