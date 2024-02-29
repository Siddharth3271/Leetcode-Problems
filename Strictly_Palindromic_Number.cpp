class Solution {
public:
    bool isPalindrome(string check){
        int i=0,j=check.size()-1;
        while(i<j){
            if(check[i]!=check[j])
                return false;
            i++; j--;
        }
        return true;
    }
    bool isStrictlyPalindromic(int n) {
        //T.C.=O(n)
        //S.C.=O(1)
        for(int i=2;i<=n-2;i++){
            string rep="";
            int check=n;
            while(check){
                rep+=(to_string(check%i));
                check=check/i;
            }
            if(!isPalindrome(rep))
                return false;
        }
        return true;
    }
};
