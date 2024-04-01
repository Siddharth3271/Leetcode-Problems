class Solution {
public:
    //T.C.=O(n)
    //S.C.=O(1)
    int lengthOfLastWord(string s) {
        int idx=s.find_last_not_of(' ')+1;
        s.erase(idx);  //remove all the trailing spaces
        int last_space_idx=s.find_last_of(' ');
        return last_space_idx==string::npos? s.length():s.length()-last_space_idx-1;
        //corner case "abcd"
    }
};
