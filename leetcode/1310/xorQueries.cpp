//leetcode1310

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        //overhead (额外开销): 估算直接计算与预计算a1^...^ak的异或计算次数
        int num_xor1 = arr.size() - 1 + queries.size(), num_xor2 = 0;
        for (const vector<int>& q: queries)
            num_xor2 += q[1] - q[0];
        if (num_xor1 < num_xor2)
            return xorQueries1(arr, queries);
        return xorQueries2(arr, queries);
    }
    //首先进行预计算, 再逐个计算结果
    vector<int> xorQueries1(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> aux(arr.size() + 1, 0);
        //使用下标会比迭代器慢吗?
        aux[0] = 0;
        for (int i = 1; i < aux.size(); ++i){
            aux[i] = aux[i-1]^arr[i-1];
        }
        vector<int> res(queries.size());
        for(int i = 0; i < res.size(); ++i){
            res[i] = aux[queries[i][0]] ^ aux[queries[i][1]+1];
        }
        return res;
    }
    //直接逐个计算结果
    vector<int> xorQueries2(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res(queries.size(), 0);
        for(int i = 0; i < queries.size(); i++)
            for (int j = queries[i][0]; j <= queries[i][1]; j++)
                res[i] ^= arr[j];
        return res;
    }
};