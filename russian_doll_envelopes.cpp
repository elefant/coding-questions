class Solution {
public:
    /**
     * @param envelopes a number of envelopes with widths and heights
     * @return the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        // Write your code here
        sort(envelopes.begin(), envelopes.end());
        vector<int> sol(envelopes.size(), 1);
        int ans = 1;
        for (int i = 0; i < envelopes.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (canContain(envelopes, i, j)) {
                    sol[i] = max(sol[i], sol[j] + 1);
                }
            }
            ans = max(ans, sol[i]);
        }
        return ans;
    }

    bool canContain(vector<pair<int, int>>& envelopes, int i, int j) {
        return envelopes[i].first > envelopes[j].first &&
               envelopes[i].second > envelopes[j].second;
    }
};