class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n, mid;
        while (left < right) {
            if (nums[left] <= nums[right-1])
                return nums[left];
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid - 1])
                return nums[mid];
            if (nums[left] <= nums[mid])
                left = mid + 1;
            else
                right = mid;
        }
        return -1;
    }
};