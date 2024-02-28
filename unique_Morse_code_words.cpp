class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
    string str[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string>s;
       for(int i=0;i<words.size();i++){
           string temp="";
           for(auto &ch:words[i]){
               temp+=str[ch-'a'];
           }
           s.insert(temp);
       }
    int n=s.size();
        return n;
        //T.C.=>O(n^2)
        //S.C.=>O(n)
    }
};
