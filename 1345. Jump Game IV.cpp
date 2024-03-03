class Solution {
public:
    //T.C.=O(n)  since  we are visiting every element only ones
    //S.C.=O(n)
    int minJumps(vector<int>& arr) {
        int n=arr.size();  //last index=n-1;
        unordered_map<int,vector<int>>mp;
        vector<int>visited(n,false);
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i); //number->index1,index2,index3....
        }
        queue<int>q;
        q.push(0);
        visited[0]=true;
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int currentIndex=q.front();
                q.pop();
                int left=currentIndex-1;
                int right=currentIndex+1;
                
                if(currentIndex==n-1){
                    return steps;
                }
                
                //check for out of bounds and already visited points
                if(left>=0 && !visited[left]){
                    q.push(left);
                    visited[left]=true;
                }
                if(right<=n-1 && !visited[right]){
                    q.push(right);
                    visited[right]=true;
                }
                
                for(int &idx: mp[arr[currentIndex]]){
                    if(!visited[idx]){
                        q.push(idx);
                        visited[idx]=true;
                    }
                }
                //to avoid duplicate entries in queue
                mp.erase(arr[currentIndex]);
            }
            steps++;
        }
        return -1;
    }
};
