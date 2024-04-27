int maxSubArray(int* nums, int numsSize) {
    int i,max;
    max = nums[0];
    int* maxnum = (int*)malloc(sizeof(int) * numsSize);
    maxnum[0] = nums[0];
    for(i=1;i<numsSize;++i){
        maxnum[i] = nums[i];
        if(maxnum[i]+maxnum[i-1] > maxnum[i]){
            maxnum[i] = maxnum[i] + maxnum[i-1];
        }
        if(max < maxnum[i]){
            max = maxnum[i];
        }

    }
    return max;
}