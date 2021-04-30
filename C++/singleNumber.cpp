// leetcode 137
// 给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

// 示例 1：
// 输入：nums = [2,2,3,2]
// 输出：3

// 示例 2：
// 输入：nums = [0,1,0,1,0,1,99]
// 输出：99

// 提示：
// 1 <= nums.length <= 3 * 104
// -231 <= nums[i] <= 231 - 1
// nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次

// 进阶：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？


class Solution {
public:
    int singleNumber(vector<int>& nums){
        return singleNumber_v1(nums);
    }
    int singleNumber_v1(vector<int>& nums) {
        unordered_map<int, int> freq;
		// 适用于容器遍历的简化写法
        for (int num: nums) {
            ++freq[num];
        }
        int ans = 0;
		// 简化写法
        // for (auto [num, occ]: freq) 
        // {
        //     if (occ == 1)
        //     {
        //         ans = num;
        //         break;
        //     }
        // }
		
		// 完整写法
        for (unordered_map<int, int>::iterator iter = freq.begin(); iter != freq.end(); iter++)
            if (iter->second == 1)
            {
                ans = iter -> first;
                break;
            }
        return ans;
    }
};