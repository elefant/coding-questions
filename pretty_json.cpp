vector<string> Solution::prettyJSON(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more detail
    int identCnt = 0;
    vector<string> sol(1);

    auto printNewLine = [&]() {
      sol.push_back(string());
      sol.back().append(identCnt, '\t');
    };

    for (int i = 0; i < A.size(); i++) {
        char c = A[i];
        if (c == '[' || c == '{') {
            if (i - 1 >= 0 && A[i - 1] != ',' && A[i - 1] != '[' && A[i - 1] != '{' ) {
                printNewLine();
            }
            identCnt++;
            sol.back() += c;
            printNewLine();
            continue;
        }
        if (c == ',') {
            sol.back() += c;
            printNewLine();
            continue;
        }
        if (c == ']' || c == '}') {
            identCnt--;
            printNewLine();
            sol.back() += c;
            continue;
        }
        sol.back() += c;
    }

    return sol;
}