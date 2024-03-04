class Solution {
public:
    int compress(vector<char>& chars) {
        //T.C.=O(n)
        //S.C.=O(1)
        int index=0;
        int i=0;
        int n=chars.size();
        while(i<n){
            char curr_char=chars[i];
            int count=0;
            //count the duplicates
            while(i<n && chars[i]==curr_char){
                count++;
                i++;
            }
            //assign the char and its frequency
            chars[index]=curr_char;
            index++;
            if(count>1){
                string count_str=to_string(count);
                for(char & ch: count_str){
                    chars[index]=ch;
                    index++;
                }
            }
        }
        return index;
    }
};
