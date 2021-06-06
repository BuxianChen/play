// 简洁, 且可扩展
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int dup = 2, n = nums.size();
        if (n < dup) return n;
        int j = dup;
        for (int i = dup; i < n; i++) {
            if (nums[i] != nums[j-dup])
                nums[j++] = nums[i];
        }
        return j;
    }
};