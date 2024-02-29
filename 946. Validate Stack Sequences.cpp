class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        //important points to consider for interview(ask the interviewer)
        //each have disinct value
        //initially empty stack
        //popped is a permutation of pushed
        //lengths are same
        int i=0,j=0;
        int n=pushed.size();
        stack<int>st;
        //T.C.=O(n)
        //S.C.=O(n)
        while(i<n && j<n){
            st.push(pushed[i]);
            while(!st.empty() && popped[j]==st.top() && j<n){
                st.pop();
                j++;
            }
            i++;
        }
        return st.empty();
    }
};
