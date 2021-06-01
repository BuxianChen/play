class Solution {
private:
    //using LL = long long;
    typedef long long LL;
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<LL> candyInterval(n+1);
        for(int i = 0; i < n; ++i)
            candyInterval[i+1] = candyInterval[i] + (LL)candiesCount[i];
        vector<bool> result(queries.size());
        for(int i = 0; i < result.size(); ++i){
            LL min = queries[i][1] + 1;
            LL max = (long long) (queries[i][1] + 1) * queries[i][2];
            LL candymin = candyInterval[queries[i][0]] + 1;
            LL candymax = candyInterval[queries[i][0] + 1];
            if ((candymin <= max) && (min <= candymax))
                result[i] = true;
        }
        return result;
    }
};