class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int mod = 1000000007;
        int num_works = group.size();
        //dp[i][j][k] 表示只使用第[1,i]项工作的若干项, 所用人数为j人, 利润大于等于k的方案数
        vector<vector<vector<int>>> dp(num_works+1, vector<vector<int>>(n+1, vector<int>(minProfit+1, 0)));
        dp[0][0][0] = 1;
        for (int i = 1; i < num_works+1; i++)
            for (int j = 0; j < n + 1; j++)
                for (int k = 0; k < minProfit + 1; k++){
                    if (j >= group[i-1])
                        dp[i][j][k] = (dp[i-1][j][k] + dp[i-1][j-group[i-1]][max(0, k-profit[i-1])]) % mod;
                    else
                        dp[i][j][k] = dp[i-1][j][k];
                }
        int sum = 0;
        for (int j = 0; j < n + 1; j++) {
            sum = (sum + dp[num_works][j][minProfit]) % mod;
        }
        return sum;
    }
};