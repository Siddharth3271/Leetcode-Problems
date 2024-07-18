//two pointer sliding window techniques
//4 patterns
//1. Constant Window
// for ex given up array and an integer k, you have to pick up those consecutive k elements whose sum is maximum
// take two pointers l=0 and r=k-1 move both iteravely
// if sum of elements between l and r is greater than max sum then update max sum
// if sum of elements between l and r is less than max sum then move l pointer to right
//2. Longest consecutive subarray/substring with sum<=k  (important)
//->brute force
//to generate all the subarrays
//for each subarray check if sum<=k
//if yes then update max length  (j-i+1)
//time complexity O(n^2)
//->two pointer +sliding window(better)
//take two pointers l=0 and r=0 and sum=0 initially
//move r pointer iteravely and add the element at r to sum
//if sum<=k then update max length (r-l+1) and if it is greater then try to shrink by moving the pointer l to the right
//time complexity O(n+n)
//->optimal approach(trimming the shrinking part)(if want only length)
//take two pointers l=0 and r=0 and sum=0 initially
//move r pointer iteravely and add the element at r to sum
//if sum<=k then update max length (r-l+1) and if it is greater
//then move l pointer to the right and subtract the element at l from sum
//time complexity O(n)
//3. No. of subarrays with some condition
//can be solved using 2nd pattern
//4. finding the shortest//minimum window with some condition
//can be solved using 2nd pattern



