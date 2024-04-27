

int rob(int* nums, int numsSize){
    int* dp = (int*)malloc(sizeof(int)*numsSize);
    int i,max;
    if(numsSize>=1) {
    dp[0] = nums[0];
    max = dp[0];
    }
    if(numsSize >= 2){
    dp[1] = nums[1];
    max = fmax(dp[0],dp[1]);
    }
    if(numsSize >= 3){
    dp[2] = nums[2] + dp[0];
    max = fmax(dp[1],dp[2]);
    for(i = 3;i<numsSize;++i){
        dp[i] = nums[i] + fmax(dp[i-2],dp[i-3]);
        if(dp[i] > max){
            max = dp[i];
        }       
    }
    }
    return max;
}