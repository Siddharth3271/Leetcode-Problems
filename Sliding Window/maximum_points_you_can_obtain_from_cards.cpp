#include<bits/stdc++.h>
using namespace std;
//T.C.=O(2k)
//S.C.=O(1)
int maxScore(vector<int>& cardPoints, int k) {
    int leftsum=0;
    int rightsum=0;
    int maxSum=0;
    int n=cardPoints.size();
    for(int i=0;i<=k-1;i++){
        leftsum+=cardPoints[i];
        maxSum=leftsum;
    }
    int rightindex=n-1;
    for(int i=k-1;i>=0;i--){
        leftsum=leftsum-cardPoints[i];
        rightsum+=cardPoints[rightindex];
        rightindex=rightindex-1;
        maxSum=max(maxSum,leftsum+rightsum);
    }
    return maxSum;
}
int main(){
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 3;
    int result = maxScore(cardPoints, k);
    cout << "Maximum score: " << result << endl;
    return 0;
}