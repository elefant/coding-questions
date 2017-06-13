int Solution::strStr(const string &haystack, const string &needle) {
    if (haystack.empty() || needle.empty()) {
        return -1;
    }
    if (needle.length() > haystack.length()) {
        return -1;
    }

    int needleChecksum = 0;
    int curChecksum = 0;
    for (int i = 0; i < needle.length(); i++) {
        needleChecksum += needle[i];
        curChecksum += haystack[i];
    }

    curChecksum -= haystack[needle.length() - 1];
    for (int i = 0; i <= haystack.length() - needle.length(); i++) {
        curChecksum += haystack[i + needle.length() - 1];

        // haystack.length() - needle.length() + needle.length() - 1

        if (curChecksum != needleChecksum) {
            curChecksum -= haystack[i];
            continue;
        }

        bool found = true;
        for (int j = 0; j < needle.length(); j++) {
            if (haystack[i + j] != needle[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i;
        }

        curChecksum -= haystack[i];
    }

    return -1;
}
