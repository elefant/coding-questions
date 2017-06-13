void helper(int left, int right, int A, string cur, vector<string>& sol) {
    if (left == A && right == A) {
        sol.push_back(cur);
        return;
    }
    if (left < right || left > A || right > A) {
        return;
    }
    helper(left + 1, right, A, cur + "(", sol);
    helper(left, right + 1, A, cur + ")", sol);
}


vector<string> Solution::generateParenthesis(int A) {
    vector<string> sol;
    helper(0, 0, A, "", sol);
    return sol;
}
