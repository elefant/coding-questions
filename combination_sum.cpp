void helper(vector<int>& A, int start, int B, vector<int> cur, vector<vector<int>>& aSol) {
    if (B == 0) {
        aSol.push_back(cur);
        return;
    }
    if (start >= A.size()) {
        return;
    }

    // 0 A[start]
    helper(A, start + 1, B, cur, aSol);

    // 1 to ... A[start]
    while (A[start] <= B) {
        cur.push_back(A[start]);
        helper(A, start + 1, B - A[start], cur, aSol);
        B -= A[start];
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int>> sol;
    sort(A.begin(), A.end());
    int cnt = 0;
    for (auto n: A) {
        if (cnt == 0) {
            A[0] = n;
            cnt++;
        } else if (A[cnt - 1] != n) {
            A[cnt] = n;
            cnt++;
        }
    }
    A.resize(cnt);

    helper(A, 0, B, vector<int>(), sol);
    reverse(sol.begin(), sol.end());
    return sol;
}
