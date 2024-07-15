int removeDuplicates(int* nums, int numsSize) {
    int a=1;
    if(numsSize==0){
        return 0;
    }
    for(int i=1;i<numsSize;i++){
        if(nums[i]!=nums[i-1]){
            nums[a]=nums[i];
            a++;
        }
    }
    return a;
}
