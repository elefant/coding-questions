vector<int> Solution::equal(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    unordered_map<int, pair<int, int>> sumMap;

    vector<int> sol;
    for (int i = 0; i < A.size(); i++) {
        for (int j = i + 1; j < A.size(); j++) {
            auto itr = sumMap.find(A[i] + A[j]);
            if (itr == sumMap.end()) {
                sumMap[A[i] + A[j]] = {i, j};
            } else {
                auto p = itr->second;
                if (i == p.first || i == p.second || j == p.first || j == p.second) {
                    continue;
                }
                vector<int> tmp = {p.first, p.second, i, j};
                if (sol.empty() || tmp < sol) {
                    sol = tmp;
                }
            }
        }
    }

    return sol;
}
