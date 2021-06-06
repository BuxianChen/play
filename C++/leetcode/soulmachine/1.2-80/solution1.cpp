class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size(), i = 1, j = 0, count = 1;
        while(i < n) {
            if (nums[i]==nums[j]) {
                if (count == 1) {
                    nums[++j] = nums[i];
                    count++;
                }
            }
            else {
                nums[++j] = nums[i];
                count = 1;
            }
            i++;
        }
        return ++j;
    }
};