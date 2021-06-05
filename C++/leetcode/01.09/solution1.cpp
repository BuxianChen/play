class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;
        if (s1.length() == 0)
            return true;
        return isSubString(s1, s2 + s2);
    }
private:
    bool isSubString(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        for (int i = 0; i < n - m + 1; i++) {
            int j = 0;
            for (; j < m; j++)
                if (s2[i+j] != s1[j])
                    break;
            if (j == m)
                return true;
        }
        return false;
    }
};