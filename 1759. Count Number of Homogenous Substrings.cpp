class Solution {
public:
    int MOD=1e9+7;
    int countHomogenous(string s) {
        //T.C.=O(n)
        //S.C.=O(1)
        int n=s.length();
        int sum=0;
        int length=0; //which is updated each time
        for(int i=0;i<n;i++){    //marked for revision
            if(i>0 && s[i]==s[i-1]){
                length+=1;
            }
            else{
                length=1;
            }
            sum=(sum+length)%MOD;
        }
        return sum;
    }
};
