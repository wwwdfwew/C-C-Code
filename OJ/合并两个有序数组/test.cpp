void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int end1 = m - 1;
    int end2 = n - 1;
    int det = nums1Size - 1;
    while (end2 >= 0 && end1 >= 0)
    {
        if (nums1[end1] > nums2[end2]) {
            nums1[det--] = nums1[end1];
            end1--;
        }
        else if (nums1[end1] < nums2[end2])
        {
            nums1[det--] = nums2[end2];
            end2--;
        }
        else {
            nums1[det--] = nums2[end2];
            end2--;
        }
    }
    while (end2 >= 0)
    {
        nums1[det--] = nums2[end2--];
    }


}