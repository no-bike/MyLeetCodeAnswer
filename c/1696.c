int maxResult(int* nums, int numsSize, int k) {
    int* dp = (int*)malloc(sizeof(int)*numsSize);//从0到i含第i位数字的最大子序列和
    int i,j,flag,temp;
    dp[0] =nums[0];
    flag = -k;
    for(i=1;i<numsSize;++i){
        if(flag < i-k){
            j = fmax(0,i-k);
            temp = dp[j];
            for(;j<i;++j){
                if(dp[j] >= temp){
                    temp = dp[j];
                    flag = j;
                }
            }
        }
        dp[i] = nums[i] + dp[flag];
        if(dp[i] > dp[flag]){
            flag = i;
        }
    } 
    return dp[numsSize-1]; 
}