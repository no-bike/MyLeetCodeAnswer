

int minSubArrayLen(int target, int* nums, int numsSize){
    int i,minsize,j,temp;
    int* dp = (int*)malloc(sizeof(int)*(numsSize+1));
    dp[0] = 0;
    for(i=0;i<numsSize;++i){
        dp[i+1] = dp[i] + nums[i];
    }//前缀和
    if(dp[numsSize] < target) return 0;
    j=0;
    minsize = numsSize;
    for(i=0;i<numsSize;++i){
        if(dp[i+1] - dp[j] >= target){
            temp = i - j + 1;
            while(dp[i+1] - dp[j+1] >= target){
                --temp;
                ++j;
            }
            if(minsize > temp){
                minsize = temp;
            }
        }
    }
    return minsize;
}