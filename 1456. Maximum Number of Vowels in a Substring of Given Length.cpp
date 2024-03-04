class Solution {
public:
    bool isVowel(char &ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    int maxVowels(string s, int k) {
        //T.C.=O(n)
        //S.C.=O(1)
        int n=s.length();
        int i=0;int j=0;
        int maxV=0;
        int count=0;
        while(j<n){
            if(isVowel(s[j])){
                count++;
            }
            if(j-i+1==k){
                maxV=max(maxV,count);
                if(isVowel(s[i]))
                    count--;
                i++;     //shifting window to right hand side
            }
            j++;
        }
        return maxV;
    }
};
