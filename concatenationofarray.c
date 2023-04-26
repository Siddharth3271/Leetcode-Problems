int* getConcatenation(int* nums, int numsSize, int* returnSize){
    *returnSize=2 * numsSize;
    int* ans=(int*)malloc((*returnSize)*sizeof(int));
    // for(int i=0;i<numsSize;i++)
    // {
    //     scanf("%d",nums[i]);
    // }
    //int*ptr=realloc(nums,returnSize);
    
    for(int i=0;i<numsSize;i++)
    {
        ans[i]=nums[i];
        ans[numsSize+i]=nums[i];
    }
    return ans;
}
