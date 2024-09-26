void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int i = nums1Size, j = nums2Size, len = i + j - 1;
	--i, --j;
	while (i >= 0 && j >= 0) {
		if (nums1[i] > nums[j])
			nums1[len--] = nums1[i--];
		else
			nums1[len--] = nums2[j--];
	}
	while (j >= 0) {
		nums1[len--] = nums2[j--];
	}
}