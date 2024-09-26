//力扣209
int minSubArrayLen(int target, int* nums, int numsSize) {
	int left = 0, right = 0, sum = 0, minLen = numsize + 1, len;
	while (right < numsSize) {
		sum += nums[right];
		while (sum >= target) {
			len = right - left + 1;
			minLen = minLen < len ? minLen : len;
			sum -= nums[left];
			left++;
		}
		right++;
	}
	return min == numsSize + 1 ? 0 : minLen;
}

/*
//错解
int minSubArrayLen(int target, int* nums, int numsSize) {
	int left = 0, right = numsSize - 1, sum = 0;
	for (int i = 0; i < numsSize; ++i) {
		sum += nums[i];
	}
	if (sum < target)
		return 0;
	while (sum >= target && left < right) {
		if (nums[left] < nums[right]) {
			sum -= nums[left];
			left++;
		} else{
			sum -= nums[right];
			right--;
		}
	}
	if (left == right){
		if(sum>=target)
			return 1;
		else return 2;
	}
	return right - left + 2;
}*/