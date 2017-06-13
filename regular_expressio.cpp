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