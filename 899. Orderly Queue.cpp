class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());  //simply sort for k>1 
            return s;
        }
        string result=s;
        for(int i=1;i<=s.length()-1;i++){
            string temp=s.substr(i)+s.substr(0,i);
            result=min(result,temp);
        }
        return result;
    }
};

/*
Time Complexity:

    If k > 1, the time complexity is dominated by the sorting operation, which is O(n log n), where n is the length of the string s.
    If k = 1, the time complexity is O(n^2), where n is the length of the string s, as we iterate through all possible cyclic shifts.

Space Complexity:

    The space complexity is O(n), where n is the length of the string s, as we use additional space to store the result and temporary strings during cyclic shifts.
*/
