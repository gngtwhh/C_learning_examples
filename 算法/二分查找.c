#include <stdio.h>
int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize, mid = left + (right - left) / 2;
    while (left != right && nums[mid] != target) {
        if (target < nums[mid])
            right = mid;
        else
            left = mid + 1;
        mid = left + (right - left) / 2;
    }
    if (mid == right)
        return -1;
    return mid;
}
#if 0
int search(int* nums, int numsSize, int target) {
    int idx, left = 0, right = numsSize - 1;
    while (left <= right) {
        idx = (left + right) / 2;
        if (nums[idx] < target)
            left = idx + 1;
        else if (nums[idx] > target)
            right = idx - 1;
        else return idx;
    }
    return -1;
}
#endif
int main() {
    int nums[100], n,target;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }
    scanf("%d",&target);
    printf("%d",search(nums,n,target));
    return 0;
}