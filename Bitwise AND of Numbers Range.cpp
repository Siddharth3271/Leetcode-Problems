//approach 1
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        //T.C.=(log n)  worst case(representing total no. of bits of any binary number)
        //S.C.=O(1)
        int shiftcount=0;
        while(left!=right){
            //longest common prefix finding
            left=(left>>1);
            right=(right>>1);    //right shift
            shiftcount++;
        }
        return (left<<shiftcount);    //left shift
    }
};

//approach 2
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        //T.C.=O(log n)  worst case (resetting all bits)
        //S.C=O(1)
        //n&(n-1) method
        //1. clears the right most set bit
        //2. helps to find number of set bits
        //3. check power of 2
        while(right>left){
            right=right&(right-1);
        }
        return right;
    }
};
