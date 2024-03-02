class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        long long sum=0;
        int j=0;
        for(int i=n-2;i>=0;i-=2){
            if(j>=i){
                break;
            }
            else{
                sum+=piles[i];
                j++;
            }
        }
        return sum;
    }
};
