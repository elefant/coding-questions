void helper(const string& str, int pos, multiset<string> subs, int start, set<int>& sol) {
    if (subs.empty()) {
        sol.insert(start);
        return;
    }

    auto subs2 = subs;
    for (auto sub: subs) {
        if (0 == strncmp(&str[pos], sub.c_str(), sub.length())) {
            subs2.erase(subs2.find(sub));
            helper(str, pos + sub.length(), subs2, start, sol);
            subs2.insert(sub);
        }
    }
}

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    multiset<string> subs;
    int totalLen = 0;
    uint32_t targetChecksum = 0;
    for (auto s: B) {
        subs.insert(s);
        totalLen += s.length();
        for (auto c: s) {
            targetChecksum += c;
        }
    }

    set<int> sol;

    uint32_t curChecksum = 0;
    for (int i = 0; i < totalLen - 1; i++) {
        curChecksum += A[i];
    }

    for (int i = 0; i <= (int)A.size() - totalLen; i++) {
        // Check the boundary with (A.size() == totalLen)
        curChecksum += A[i + totalLen - 1];
        if (curChecksum == targetChecksum) {
            string candidate = A.substr(i, totalLen); // A[i...(i+totalLen-1)]
            helper(candidate, 0, subs, i, sol);
        }
        curChecksum -= A[i];
    }

    return vector<int>(sol.begin(), sol.end());
}

