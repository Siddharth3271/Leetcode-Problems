class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        //jab tak score bad sakta hai badate hain
        //T.C.=O(n)
        //S.C.=O(1)
        sort(tokens.begin(),tokens.end());
        //ith index se score++ karenge power gavan kar
        //jth index se power ko increase karenge score gavan kar
        int n=tokens.size();
        int maxScore=0; //initially
        int i=0,j=n-1;
        int score=0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score+=1;
                i++;
                maxScore=max(maxScore,score);
            }
            else if(score>=1){
                power+=tokens[j];
                score--;
                j--;
            }
            else{
                return maxScore;
            }
        }
        return maxScore;
    }
};
