#include<iostream>
#define MAX 100000
using namespace std;
void pop(int st[], int *top) {
    if (*top == -1) {
        cout << "STACK UNDERFLOW" << endl;
        //return -1;  // Return an invalid value for underflow
    } else {
        st[(*top)--];  // Return the top element and decrement
    }
}

void push(int st[],int *top,char value)
{
    if(*top==(MAX-1))
    {
        cout<<"STACK OVERFLOW"<<endl;
    }
    else
    {
        st[++(*top)]=value;
    }
}
// int top(int st[],int top){
//     return st[top];
// }
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int top=-1;
        int st[MAX];
        long long int  j=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                if(top>=0)
                {
                    ans.push_back(s[i]);
                }
                push(st,&top,s[i]);
            }
            else{
                pop(st,&top);
                if(top>=0)
                {
                    ans.push_back(s[i]);
                }
            }
        }
        return ans;
    }
    
};