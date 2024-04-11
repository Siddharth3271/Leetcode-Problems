class Solution {
public:
    string removeKdigits(string num, int k) {
        string res="";  //it will act like a stack
        //T.C.=O(2*n)
        //S.C.=O(1)  auxillary space
        if(k==0)  return num;
        if(k==num.length()) return "0";
        int n=num.length();
        for(int i=0;i<n;i++){
            while(res.length()>0 && res.back()>num[i] && k>0){
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }
        //if input was "12345"
        while(k>0){
            res.pop_back();
            k--;
        }
        //to remove preceding zeroes
        while(res.length()>1 && res[0]=='0'){
            res.erase(res.begin() + 0);
        }
        return res;
    }
};
