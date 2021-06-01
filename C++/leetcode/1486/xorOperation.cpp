class Solution {
public:
    //0^1^2^...^x
    int sumXor(int x){
        if (x % 4 == 0)
            return x;
        if (x % 4 == 1)
            return 1;
        if (x % 4 == 2)
            return x + 1;
        return 0;
    }
    int xorOperation(int n, int start) {
        int x = start >> 1;
        return (sumXor(n + x - 1) ^ sumXor(x - 1)) << 1 | (n & start & 1);
    }
};