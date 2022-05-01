#include<vector>

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i)
            for (int j = 0; j <= i; j++)
                triangle[i][j] = min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j];
        return triangle[0][0];
    }
};

// void test01() {

//     Solution().minimumTotal()
// }

// int main(int argc, char* argv[]) {
//     test01();
//     return 0
// }