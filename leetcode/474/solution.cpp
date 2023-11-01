class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        vector<vector<int>> counts(k, vector<int>(2, 0));
        get01nums(strs, counts);

        for (auto &a: counts)
            cout << a[0] << " " << a[1] << endl;
        vector<vector<vector<int>>> table(k+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        for (int i = 1; i < k+1; i++)
            for (int j = 0; j < m+1; j++)  // 这里要从0开始
                for (int x = 0; x < n+1; x++) {
                    int zeros = counts[i-1][0], ones = counts[i-1][1];
                    if ((zeros > j) || (ones > x))
                        table[i][j][x] = table[i-1][j][x];
                    else
                        table[i][j][x] = max(table[i-1][j][x], 1 + table[i-1][j-zeros][x-ones]);
                }
        return table[k][m][n];
    }
private:
    void get01nums(vector<string> &strs, vector<vector<int>> &res){
        for (int i = 0; i < strs.size(); i++) {
            const string &s = strs[i];
            for (char c: s)
                c == '0' ? res[i][0]++ : res[i][1]++;
        }
    }
};