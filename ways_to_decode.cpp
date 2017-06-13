int Solution::numDecodings(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (A.empty()) {
        return 0;
    }

    vector<int> sol(A.length(), 0);

    auto decodable = [](char a, char b) -> bool {
        if (a == '0') {
            return false;
        }
        return (a - '0') * 10 + (b - '0') <= 26;
    };

    for (int i = 0; i < sol.size(); i++) {
        if (i == 0) {
            sol[i] = (A[i] == '0' ? 0 : 1);
        } else {
            if (A[i] != '0') {
                sol[i] += sol[i - 1];
            }
            if (decodable(A[i - 1], A[i])) {
                sol[i] += (i - 2 >= 0 ? sol[i - 2] : 1);
            }
        }
    }

    return sol.back();
}
