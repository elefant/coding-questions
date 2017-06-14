class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freqCnt(256);
        for (auto c: t) {
            freqCnt[c]++;
        }
        int left = 0;
        int right = 0;
        int remain = t.length();
        string sol;
        while (right < s.length()) {
            // Take s[right]
            if (freqCnt[s[right]] > 0) {
                remain--;
            }
            freqCnt[s[right]]--; // negative is okay
            right++;

            while (remain == 0) {
                // s[left] ... s[right-1] is one solution.
                string tmpSol = s.substr(left, right - left);
                if (sol.empty() || tmpSol.length() < sol.length()) {
                    sol = tmpSol;
                }
                // Update the freqCnt and shrink window
                freqCnt[s[left]]++;
                left++;
                // Check if every freqCnt[] is still <= 0. Only need to check freqCnt[s[left-1]]
                if (freqCnt[s[left-1]] > 0) {
                    remain++;
                }
            }
        }
        return sol;
    }
};