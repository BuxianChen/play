//leetcode 1734

/*
给你 encoded 数组，请你返回原始数组 perm 。题目保证答案存在且唯一。
给你一个整数数组 perm ，它是前 n 个正整数的排列，且 n 是个 奇数 。
它被加密成另一个长度为 n - 1 的整数数组 encoded ，满足 encoded[i] = perm[i] XOR perm[i + 1] 。比方说，如果 perm = [1,3,2] ，那么 encoded = [2,1] 。

示例 1：
输入：encoded = [3,1]
输出：[1,2,3]
解释：如果 perm = [1,2,3] ，那么 encoded = [1 XOR 2,2 XOR 3] = [3,1]

示例 2：
输入：encoded = [6,5,4,6]
输出：[2,4,1,5,3]

提示
3 <= n < 10^5
n 是奇数。
encoded.length == n - 1

*/

//O(n)复杂度
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        vector<int> res(encoded.size()+1);
        //首先O(1)时间计算1^2^...^k, 由k%4决定
        res[0] = (encoded.size()/2 + 1) % 2;
        //计算第一个数
        for(int i = 1; i < encoded.size(); i+=2)
            res[0] ^= encoded[i];
        //计算其余数
        for(int i = 1; i < res.size(); ++i)
            res[i] = res[i-1]^encoded[i-1];
        return res;
    }
};