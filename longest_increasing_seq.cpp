int Solution::lis(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> sol(A.size(), 1);
    int globalMax = 1;
    for (int i = 0; i < sol.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                sol[i] = max(sol[i], sol[j] + 1);
            }
        }
        globalMax = max(globalMax, sol[i]);
    }

    return globalMax;
}
