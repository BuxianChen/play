class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        dp[0][0] = 1;
        for (int i=1; i<n+1; i++)
            for (int j=0; j<amount+1; j++) {
                dp[i][j] = dp[i-1][j];
                for (int k=1;;k++)
                    if (coins[i-1]*k <= j)
                        dp[i][j] += dp[i-1][j-coins[i-1]*k];
                    else
                        break;
            }
        return dp[n][amount];
    }
};