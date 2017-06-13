string Solution::countAndSay(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string sol = "1";
    for (int i = 1; i < A; i++) {
        string nextSol;
        int cnt = 1;
        sol += 'X';
        char cur = sol[0];
        for (int j = 1; j < sol.length(); j++) {
            if (sol[j] == cur) {
                cnt++;
            } else {
                nextSol += ('0' + cnt);
                nextSol += cur;
                cnt = 1;
                cur = sol[j];
            }
        }
        swap(nextSol, sol);
    }
    return sol;
}