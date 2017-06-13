int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = A.size();
    if (m == 0) {
        return 0;
    }
    int n = A[0].size();
    vector<vector<int>> sol(m, vector<int>(n, 0));
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (A[r][c] == 1) {
                sol[r][c] = 0;
            } else if (r == 0 && c == 0) {
              sol[r][c] = 1;
            } else {
                if (r - 1 >= 0) {
                    sol[r][c] += sol[r - 1][c];
                }
                if (c - 1 >= 0) {
                    sol[r][c] += sol[r][c - 1];
                }
            }
        }
    }
    return sol.back().back();
}
