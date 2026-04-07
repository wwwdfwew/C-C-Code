void rotate(int* nums, int numsSize, int k) {
    int* nums1 = (int*)malloc(sizeof(int) * numsSize);
    k = k % numsSize;
    for (int i = 0; i < k; i++)
    {
        nums1[i] = nums[numsSize - k + i];
    }
    for (int i = 0; i < numsSize - k; i++)
    {
        nums1[k + i] = nums[i];
    }
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] = nums1[i];
    }
}