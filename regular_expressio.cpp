class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p && *(p + 1) == '*') {
            // 0 recurrence.
            if (isMatch(s, p + 2)) {
                return true;
            }

            // 1+ recurrence of *p
            while (*s == *p || (*s && *p == '.')) {
                if (isMatch(s + 1, p + 2)) {
                    return true;
                }
                s++;
            }
            return false;
        }


        if (*p != *s) {
            if (*p == '.' && *s) {
                return isMatch(s + 1, p + 1);
            }
            return false;
        }
        if (*s == '\0') {
            return true;
        }
        return isMatch(s + 1, p + 1);

        /*
        if (*s == *p || (*s && *p == '.')) {
            if (*s == '\0') {
                return true;
            }
            return isMatch(s + 1, p + 1);
        }

        return false;
        */
    }
};

///////////////////////////////////////////////////////////////////////

using StrPair = pair<const char*, const char*>;
map<StrPair, int> matchCache;

int match(const char* s, const char* p) {
    StrPair args(s, p);

    if (matchCache.count(args)) {
        //return matchCache[args];
    }

    if (*s == '\0' && *p == '\0') {
        matchCache[args] = 1;
        return 1;
    }
    if (*p == '*') {
        // s: ^^^^^^^$
        // p: *^^$
        while (*s) {
            if (match(s, p + 1)) {
                matchCache[args] = 1;
                return 1;
            }
            s++;
        }
        int ret = match(s, p + 1);
        matchCache[args] = ret;
        return ret;
    }
    if (!(*s && *p)) {
        matchCache[args] = 0;
        return 0;
    }
    if (*s != *p && *p != '?') {
        matchCache[args] = 0;
        return 0;
    }
    int ret = match(s + 1, p + 1);
    matchCache[args] = ret;
    return ret;
}

int Solution::isMatch(const string &s, const string &p) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return match(s.c_str(), p.c_str());
}
