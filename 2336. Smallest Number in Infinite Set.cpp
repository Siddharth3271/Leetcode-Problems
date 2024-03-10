class SmallestInfiniteSet {
public:
    //basic approach
    //T.C.=O(n)
    //S.C.=O(n)
    int i;  //pointing to current smallest
    vector<bool>nums;
    SmallestInfiniteSet() {
        nums=vector<bool>(1001,true);
        i=1;
    }
    
    int popSmallest() {
        int res=i;
        nums[i]=false;
        //i++ nahi karenge kyoki beech mey koi bhi element pop ho jata hai
        for(int j=i+1;j<1001;j++){
            if(nums[j]==true){
                i=j;   //pointing to next true element
                break;
            }
        }
        return res;
    }
    
    void addBack(int num) {
        nums[num]=true;
        if(num<i){
            i=num;   //putting back the pointer if smaller found than popped element 
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */






//approach 2
class SmallestInfiniteSet {
public:
    //T.C.=O(log n)
    //S.C.=O(n)
    int currSmallest;
    unordered_set<int>st;
    priority_queue<int,vector<int>,greater<int>>pq;
    SmallestInfiniteSet() {
        currSmallest=1;
    }
    
    int popSmallest() {
        int result;
        if(!pq.empty()){
            result=pq.top();
            pq.pop();
            st.erase(result);
        }else{
            result=currSmallest;
            currSmallest+=1;
        }
        return result;
    }
    
    void addBack(int num) {
        if(num>=currSmallest || st.find(num)!=st.end()){
            return;
        }
        st.insert(num);
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */


//approach 3
class SmallestInfiniteSet {
public:
    //T.C.=O(log n)
    //S.C.=O(n)
    int currSmallest;
    set<int>st;
    SmallestInfiniteSet() {
        currSmallest=1;
    }
    
    int popSmallest() {
        int result;
        if(!st.empty()){
            result=*st.begin();
            st.erase(st.begin());
        }else{
            result=currSmallest;
            currSmallest+=1;
        }
        return result;
    }
    
    void addBack(int num) {
        if(num>=currSmallest || st.find(num)!=st.end()){
            return;
        }
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
