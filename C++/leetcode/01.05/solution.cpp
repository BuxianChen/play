class Solution {
public:
    bool oneEditAway(string first, string second) {
        int n = first.length(), m = second.length();
        if (abs(n-m) > 1)
            return false;
        // 改
        else if (n == m) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                count += (first[i] != second[i]);
                if (count > 1)
                    return false;
            }
            return true;
        }
        // 增
        else if (n < m) {
            int i = 0;
            for (; (i < n) && (first[i] == second[i]); i++);
            if (i == n)
                return true;
            else {
                for (; (i < n) && (first[i] == second[i+1]); i++);
                return i == n;
            }
        }
        // 删
        else {
            int i = 0;
            for (; (i < m) && (first[i] == second[i]); i++);
            if (i == m)
                return true;
            else {
                for (; (i < m) && (first[i+1] == second[i]); i++);
                return i == m;
            }
        }
    }
};