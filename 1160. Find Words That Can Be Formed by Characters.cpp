class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        //T.C.=O(m*n)
        //S.C.=O(26) constant space
        vector<int>v(26,0);//for storing character frequency of chars
        for(char &ch: chars){
            v[ch-'a']++;
        }
        int result=0;
        for(string &word:words){  //O(m) chars length
            //storing each word frequency in a separate array
            vector<int>check(26,0);
            for(char& ch:word){   //O(n)  word length in a vector
                check[ch-'a']++;
            }
            bool flag=true;
            for(int i=0;i<26;i++){
                if(check[i]>v[i]){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                result+=word.length();
            }
        }
        return result;
    }
};
