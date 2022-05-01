//leetcode 554: 暴力法(失败)
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        vector<vector<int>> helper;
        int nrows = wall.size();
        int total_len = 0;
        for (auto const &len: wall[0]){
            total_len += len;
        }
        for (int i = 0; i < nrows; i++){
            helper.push_back(vector<int>(total_len+1));
            int acc = 0;
            for(auto const &len: wall[i]){
                acc += len;
                helper[i][acc] = 1;
            }
        }
        int result = 0;
        for (int i = 1; i < total_len; i++){
            int cur = 0;
            for(int row = 0; row < nrows; row++)
                cur += helper[row][i];
            result = result > cur ? result : cur;
        }
        return nrows - result;
    }
};