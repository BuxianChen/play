// leetcode 12

class Solution {
public:
    string intToRoman(int num) {
        const char tags[4][2] = {{'M', '\0'}, {'C', 'D'}, {'X', 'L'}, {'I', 'V'}};
        int mod = 1000, k = 0;
        string res;
        for (int i = 0; i < 4; i++)
        {
            k = num / mod;
            if (k == 9) {
                res.push_back(tags[i][0]);
                res.push_back(tags[i-1][0]);
            }
            else if (k > 4){
                res.push_back(tags[i][1]);
                for (int j = 0; j < k - 5; j++)
                    res.push_back(tags[i][0]);
            }
            else if (k == 4){
                res.push_back(tags[i][0]);
                res.push_back(tags[i][1]);
            }
            else{
                for (int j = 0; j < k; j++)
                    res.push_back(tags[i][0]);
            }
            num = num % mod;
            mod /= 10;
        }
        return res;
    }
};