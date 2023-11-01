class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int idx = findMin(nums);
        if (target <= nums[n - 1])
            return bsearch(nums, target, idx, n);
        else
            return bsearch(nums, target, 0, idx);
    }
private:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n, mid;
        while (left < right) {
            if (nums[left] <= nums[right-1])
                return left;
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid - 1])
                return mid;
            if (nums[left] <= nums[mid])
                left = mid + 1;
            else
                right = mid;
        }
        return -1;
    }

    int bsearch(vector<int> const &nums, int target, int i, int j) {
        int mid;
        while (i < j) {
            mid = i + (j - i) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) i = mid + 1;
            else j = mid;
        }
        return -1;
    }
};