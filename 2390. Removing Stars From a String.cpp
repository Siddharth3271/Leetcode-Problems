class Solution {
public:
    string removeStars(string s) {
        //by stack
        //T.C.=O(n)
        //S.C.=O(n)
        stack<char>st;
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                st.pop();
            }
            else
                st.push(s[i]);
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};



class Solution {
public:
    string removeStars(string s) {
        //by string
        //T.C.=O(n)
        //S.C.=O(n)
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                ans.pop_back();
            }
            else
                ans.push_back(s[i]);
        }
        
        return ans;
    }
};



class Solution {
public:
    string removeStars(string s) {
        //by two pointers
        //T.C.=O(n)
        //S.C.=O(n)
        int n=s.length();
        vector<char>temp(n);
        string ans="";
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                j--;
            }
            else{
                temp[j]=s[i];
                j++;
            }
        }
        for(int k=0;k<j;k++){
            ans+=temp[k];
        }
        return ans;
    }
};
