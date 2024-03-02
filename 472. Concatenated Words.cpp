class Solution {
public:
    int n;
    unordered_map<string, bool> mp;
    //T.C=O(n*l^3)
    //S.C=O(n)
    bool isConcat(string word, unordered_set<string>& st) {
        
        if(mp.find(word) != mp.end())
            return mp[word];
        
        int l = word.length();
        
        for(int i = 0; i<l; i++) {
            string prefix  = word.substr(0, i+1);
            string suffix  = word.substr(i+1);
            
            if((st.find(prefix) != st.end() && isConcat(suffix, st)) ||
               (st.find(prefix) != st.end() && st.find(suffix) != st.end()))
                return mp[word] = true;
        }
        
        
        return mp[word] = false;
        
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        n = words.size();
        mp.clear();
        vector<string> result;
        unordered_set<string> st(begin(words), end(words));
        
        for(int i = 0; i<n; i++) {
            if(isConcat(words[i], st))
                result.push_back(words[i]);
        }
        
        return result;
    }
};
