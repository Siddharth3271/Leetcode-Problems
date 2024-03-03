class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>>mp;
        //T.C.=O(n*m)
        //S.C=O(n)
        int m=mat.size();
        int n=mat[0].size();
        vector<int>res;
        //fill the map using i+j as keys
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        //alternatively flipping the values
        bool flip=true;
        for(auto &it: mp){
            if(flip){
                //it.second ko reverse kardo
                reverse(it.second.begin(),it.second.end());
            }
            for(int &num: it.second){
                res.push_back(num);
            }
            flip=!flip;
        }
        return res;
    }
};
