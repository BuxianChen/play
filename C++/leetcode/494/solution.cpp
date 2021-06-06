class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        backtrack(nums, target, 0, 0, count);
        return count;
    }
private:
    void backtrack(vector<int>& nums, int target, int i, int sum, int &count){
        if (i == nums.size()) {
            if (sum == target)
                count++;
        }
        else {
            backtrack(nums, target, i + 1, sum + nums[i], count);
            backtrack(nums, target, i + 1, sum - nums[i], count);
        }
    }
};