class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            int right = n - i;
            for (int j = i; j < right - 1; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[right - 1 - j + i][i];
                matrix[right - 1 - j + i][i] = matrix[right - 1][right - 1 - j + i];
                matrix[right - 1][right - 1 - j + i] = matrix[j][right - 1];
                matrix[j][right - 1] = temp;
            }
        }
    }
};