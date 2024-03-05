class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        //T.C.=O(n)
        //S.C.=O(n)
        int freq[26]={0};
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        string ans(s.size(),'_');
        int k=0;
        set<int>st;   //used to fill gaps for other characters(store indices of gaps)
        for(int i=25;i>=0;i--){   //since we want largest therefore iterate from last
            int cnt=0,curr=0;   //cnt is for how many times we have used this character
            while(cnt<freq[i] && st.size()){
                ans[*st.begin()]=(i+'a');  //filling in gaps
                st.erase(st.begin());
                cnt++;
            }
            while(cnt<freq[i]){
                if(curr==repeatLimit)
                    st.insert(k),k++,curr=0;  //if gap comes then move k to next position
                if(k>s.size())
                    break;
                ans[k]=(i+'a');
                k++,curr++,cnt++;
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='_'){    //if some gaps are remaining then remove from that gap substring
                ans.erase(ans.begin()+i,ans.end());
                break;
            }
        }
        return ans;
    }
};
