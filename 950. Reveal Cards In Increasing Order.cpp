
//approach 1
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        //T.C.=O(n log n)
        //S.C.=O(1)  auxilliary space
        int n=deck.size();
        vector<int>res(n,0);
        sort(deck.begin(),deck.end());
        bool skip=false;
        int i=0;   //deck traversal
        int j=0;   //res traversal
        while(i<n){
            if(res[j]==0){   //khali hai
                if(skip==false){
                    res[j]=deck[i];
                    i++;
                }
                skip=!skip;   //alternate
            }
            j=(j+1)%n;   //to prevent out of bounds
        }
        return res;
    }
};

//approach 2
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        //T.C.=O(n)
        //S.C.=O(n)
        int n=deck.size();
        queue<int>qu;
        vector<int>res(n);
        sort(deck.begin(),deck.end());
        for(int i=0;i<n;i++){
            qu.push(i);
        }
        for(int i=0;i<n;i++){
            int idx=qu.front();
            qu.pop();
            res[idx]=deck[i];
            if(!qu.empty()){
                qu.push(qu.front());
                qu.pop();
            }
        }
        return res;
    }
};
