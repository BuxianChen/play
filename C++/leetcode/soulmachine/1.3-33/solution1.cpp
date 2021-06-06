class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size(), mid;
		while(left < right){
			mid = left + (right - left) / 2;
			if (target == nums[mid])
				return mid;
			if (nums[left] <= nums[mid]) {
				if (target < nums[mid] && target >= nums[left]) left = mid + 1;
				else right = mid;
			}
			else {
				if (target > nums[mid] && target <= nums[right - 1]) left = mid + 1;
				else right = mid;
			}
		}
		return -1;
	}
}