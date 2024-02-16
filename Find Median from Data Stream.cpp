class MedianFinder {
public:
/*
Time Complexity:

    addNum(int num):
        Inserting an element into a priority queue takes O(log n) time, where n is the number of elements in the priority queue.
        Adjusting the size of the heaps to maintain balance takes O(1) time.
        Therefore, the time complexity of addNum is O(log n).

    findMedian():
        If the sizes of both heaps are equal, finding the median involves accessing the top elements of both heaps, which takes O(1) time.
        If the sizes are not equal, accessing the top element of pqleft takes O(1) time.
        Therefore, the time complexity of findMedian is O(1).

Space Complexity:

    The space complexity of the MedianFinder class mainly depends on the space used by the two priority queues (pqleft and pqright).
    The space used by each priority queue is O(n), where n is the number of elements inserted.
    Therefore, the overall space complexity is O(n) to store the input elements in the priority queues.

In summary:

    Time Complexity:
        addNum(int num): O(log n)
        findMedian(): O(1)
    Space Complexity:
        O(n)


*/
priority_queue<int>pqleft;  //max heap
priority_queue<int,vector<int>,greater<int>>pqright;  //min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pqleft.empty() || num<pqleft.top()){
            pqleft.push(num);
        }
        else{
            pqright.push(num);
        }
        //maintain the size of left heap one greater than right heap
        //or make their size same
        if(abs((int)pqleft.size()-(int)pqright.size())>1){
            pqright.push(pqleft.top());
            pqleft.pop();
        }
        else if(pqleft.size()<pqright.size()){
            pqleft.push(pqright.top());
            pqright.pop();
        }
    }
    
    double findMedian() {
        if(pqleft.size()==pqright.size()){   //even no. of elements in both heap
            double mean=(pqleft.top()+pqright.top())/2.0;
            return mean;
        }
        else{
            //odd elements
            return pqleft.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
