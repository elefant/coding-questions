class Solution {
public:
    /**
     * @param costs n x k cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>>& costs) {
        // Write your code here
        int numHouses = costs.size();
        if (numHouses == 0) {
            return 0;
        }

        int numColors = costs[0].size();

        vector<vector<int>> sol(numHouses, vector<int>(numColors, 0));
        for (int i = 0; i < numHouses; i++) {
            for (int j = 0; j < numColors; j++) {
                // j is the color for house[i]
                if (i == 0) {
                    sol[0][j] = costs[i][j];
                    continue;

                }
                sol[i][j] = INT_MAX;
                for (int k = 0; k < numColors; k++) {
                    // k is the color for house[i - 1]
                    if (j != k) {
                        sol[i][j] = min(sol[i][j], sol[i - 1][k] + costs[i][j]);
                    }
                }
            }
        }

        int minCost = INT_MAX;
        for (auto c: sol.back()) {
            minCost = min(minCost, c);
        }
        return minCost;
    }
};