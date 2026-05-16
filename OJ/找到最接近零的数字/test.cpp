int findClosestNumber(int* nums, int numsSize) {
    int min = nums[0];
    for (int i = 0; i < numsSize; i++)
    {
        if (abs(min) > abs(nums[i]))
            min = nums[i];
        if (abs(min) == abs(nums[i]))
        {
            if (min < nums[i])
                min = nums[i];
        }
    }
    return min;
}