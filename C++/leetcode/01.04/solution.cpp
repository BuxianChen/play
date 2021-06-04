class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        for (const char& c: s) m[c]++;
        int count = 0;
        for (auto const& [c, num]: m) {
            if (num % 2)
                count += 1;
            if (count > 1)
                return false;
        }
        return true;
    }
};
};