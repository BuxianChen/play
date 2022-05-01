//leetcode 1269

class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int prime = 1000000007;
        vector<vector<int>> a(2, vector<int>(arrLen, 0));
        a[0][0] = 1;
        for (int i = 1; i < steps; i++){
            //此题的陷阱: 这里501之后不计算是因为题目限制了steps<=500, 所以不用考虑长的路径
            for (int j = 0; j < min(501,arrLen); j++)
            {
                a[i%2][j] = a[(i+1)%2][j];
                if (j > 0)
                    a[i%2][j] = (a[i%2][j] + a[(i+1)%2][j-1]) % prime;
                if (j < arrLen-1)
                    a[i%2][j] = (a[i%2][j] + a[(i+1)%2][j+1]) % prime;
            }
        }
        return (a[(steps-1)%2][0] + a[(steps-1)%2][1]) % prime;
    }
};