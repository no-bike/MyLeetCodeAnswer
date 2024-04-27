int numSubarraysWithSum(int* nums, int numsSize, int goal){
    if(goal > numsSize) return 0;
    
    int* subarrnum = (int*)malloc(sizeof(int) * numsSize);
    int i,j,temp;
    int sum = 0;
    subarrnum[0] = nums[0];
    for(i = 1;i<numsSize;++i){
        //求前缀和！
        subarrnum[i] = nums[i] + subarrnum[i-1];
    }
    //根据前缀和构建哈希表，再二分查找
    int hashsize;
    hashsize = subarrnum[numsSize - 1] + 1;
    int* sshash = (int*)malloc(sizeof(int) * hashsize);
    for(i = 0;i<hashsize;++i){
        sshash[i] = 0;
    }
    j = 0;
    for(i = 0;i<numsSize;i++){
        sshash[subarrnum[i]]++;        
    }
    //二分查找处理哈希表
    if(goal != 0){
        if(goal > hashsize - 1){
            return 0;
        }
        sum += (sshash[0]+1)*sshash[goal];
        for(i = goal+1;i<hashsize;++i){
            //距离永远不变
            sum += (sshash[i - goal]*sshash[i]);
        }
    }
    else{
        //处理goal == 0
        for(i = 1;i<=sshash[0];++i){
            sum += i;
        }
        for(j = 1;j < hashsize;++j){
            for(i = 1;i<sshash[j];++i){
                sum += i;
            }
        }

    }
    return sum;
}