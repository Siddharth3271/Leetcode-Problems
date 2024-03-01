class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        //T.C.=O(n log n)
        //S.C.=O(n)
        set<int>s1(nums1.begin(),nums1.end());
        set<int>s2(nums2.begin(),nums2.end());
        int n=nums1.size();
        vector<int>v1;
        vector<int>v2;
        
        //putting unique elements of set1 into v1
        set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(),back_inserter(v1));
        //putting unique elements of set2 into v2
        set_difference(s2.begin(),s2.end(),s1.begin(),s1.end(),back_inserter(v2));

        return {v1,v2};
    }
};
