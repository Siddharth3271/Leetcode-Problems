class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>>s;
        //T.C.=O(n)
        //S.C.=O(n)
        int x=0,y=0;
        s.insert({x,y});
        for(int i=0;i<path.size();i++){
            if(path[i]=='E')
                x++;
            else if(path[i]=='W')
                x--;
            else if(path[i]=='S')
                y--;
            else if(path[i]=='N')
                y++;
            if(s.count({x,y}))
                return true;  //if already present in the set
            s.insert({x, y}); // if not same then insert it
        }
        return false;
    }
};
