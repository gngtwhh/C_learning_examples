//力扣75
void sortColors(int* nums, int numsSize) {
	int p0, p1, temp;
	p0 = p1 = 0;
	for (int i = 0; i < numsSize; ++i) {
		if (nums[i] == 1) {
			temp = nums[p1];
			nums[p1] = nums[i];
			nums[i] = temp;
			p1++;
		} else if (nums[i] == 0) {
			temp = nums[p0];
			nums[p0] = nums[i];
			nums[i] = temp;
			if (p0 < p1) {
				temp = nums[i];
				nums[i] = nums[p1];
				nums[p1] = temp;
			}
			++p0;
			++p1;
		}
	}
}