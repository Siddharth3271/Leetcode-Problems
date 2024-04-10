//approach 1
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //T.C.=O(n)
        //S.C.=O(n)
        int n=s.length();
        stack<int>st;
        unordered_set<int>s1;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    s1.insert(i);
                }
            }

        }
        // only open brackets=> "((("
        while(!st.empty()){
            s1.insert(st.top());
            st.pop();
        }
        string res="";
        for(int i=0;i<n;i++){
            if(s1.find(i)==s1.end()){   //not present
                res.push_back(s[i]);
            }
        }
        return res;
    }
};

//approach 2
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //T.C.=O(n)
        //S.C.=O(n)
        int n=s.length();
        //left to right=>eliminate extra close parentheses
        //right to left=>eliminate extra open parentheses
        string res="";


        //left to right=>eliminate extra close parentheses
        int open=0;
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                res+=s[i];
            }
            else if(s[i]=='('){
                open++;
                res+=s[i];
            }
            else if(open>0){
                open--;
                res+=s[i];
            }
        }

        //right to left=> eliminate extra open parentheses
        string final1="";
        int close=0;
        for(int i=res.length()-1;i>=0;i--){
            if(res[i]>='a' && res[i]<='z'){
                final1+=res[i];
            }
            else if(res[i]==')'){
                close++;
                final1+=res[i];
            }
            else if(close>0){
                close--;
                final1+=res[i];
            }
        }
        reverse(begin(final1),end(final1));
        return final1;
    }
};
