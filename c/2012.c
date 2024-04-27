int sumOfBeauties(int* nums, int numsSize) {
    int beautysum = 0;
    int frontmax;
    frontmax = nums[0];
    int rearmin[numsSize];
    rearmin[numsSize - 1] = nums[numsSize-1];
    for(int i = numsSize - 2;i>=0;--i){
        rearmin[i] = nums[i];
        if(rearmin[i]>rearmin[i+1]){
            rearmin[i] = rearmin[i+1];
        }
    }
    for(int i = 1;i<=numsSize-2;++i){
        if(nums[i] <= nums[i-1] || nums[i] >= nums[i+1]);
        else{
            if(nums[i] > frontmax && nums[i] < rearmin[i+1]){
                beautysum +=2;
            }
            if(nums[i] <= frontmax || nums[i] >= rearmin[i+1]){
                ++beautysum;
            }
        }
        if(nums[i] > frontmax){
            frontmax = nums[i];
        }
    }
    return beautysum;
}