class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        int sum = 0;
        unordered_map<int, int> sum_idx;
        sum_idx[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) sum++;
            else sum--;
            if (sum_idx.count(sum) > 0)
                maxLength = (maxLength < i - sum_idx[sum])?(i - sum_idx[sum]):maxLength;
            else
                sum_idx[sum] = i;
        }
        return maxLength;
    }
};