class Solution {
public:
    /**
     * @param num a string contains only digits 0-9
     * @param target an integer
     * @return return all possibilities
     */
    vector<string> sol;

    vector<string> addOperators(string& num, int target) {
        addOperators(num, 0, target, "", 0, 0);
        return sol;
    }

    void addOperators(string& num, int pos, int target,
                      string cur, int64_t eval, int64_t last) {
        if (pos == num.length()) {
            if (eval == target) {
                sol.push_back(cur);
            }
            return;
        }

        int64_t n = 0;
        string nstr = "";
        for (int i = pos; i < num.size(); i++) {
            char c = num[i];
            n = n * 10 + c - '0';
            nstr += c;

            if (nstr.length() == 2 && num[pos] == '0') {
                return;
            }

            if (cur.empty()) {
                addOperators(num, i + 1, target, nstr, n, n);
                continue;
            }
            addOperators(num, i + 1, target, cur + '+' + nstr, eval + n, n);
            addOperators(num, i + 1, target, cur + '-' + nstr, eval - n, -n);
            addOperators(num, i + 1, target, cur + '*' + nstr,
                         eval - last + (last * n), last * n);
        }
    }
};