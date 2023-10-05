
#include<iostream>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int max_count=0;
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                count++;
            }
            else if(s[i]==')')
            {
                if(max_count<count){
                    max_count=count;
                }
                count--;
            }
        }
        return max_count;
    }
};