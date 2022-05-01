class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> value_index;
        value_index[0] = -1;  // 这个处理很重要
        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum = (nums[i] + sum) % k;
            if (value_index.count(sum) > 0) {  // 这里忘记的大括号不能省
                if(value_index[sum] + 1 < i)
                    return true;
                }
            else
                value_index[sum] = i;
        }
        return false;
    }
};