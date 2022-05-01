class Solution {
public:
    string compressString(string S) {
        if (S.length() == 0)
            return S;
        char last = S[0];
        int count = 1;
        string result;
        for (int i = 1; i < S.size(); i++) {
            if (S[i] == last)
                count++;
            else {
                result.push_back(last);
                result.append(to_string(count));
                last = S[i];
                count = 1;
            }
        }
        result.push_back(last);
        result.append(to_string(count));
        return result.length() < S.length() ? result : S;
    }
};