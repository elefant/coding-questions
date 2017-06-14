class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        for (auto t: timePoints) {
            times.push_back(toMinutes(t));
        }
        sort(times.begin(), times.end());
        int len = times.size();
        for (int i = 0; i < len; i++) {
            times.push_back(times[i] + 1440);
        }

        int minDiff = INT_MAX;
        for (int i = 1; i < times.size(); i++) {
            minDiff = min(minDiff, times[i] - times[i - 1]);
        }
        return minDiff;
    }

    int toMinutes(const string& t) {
        return ((t[0] - '0') * 10 + (t[1] - '0')) * 60 +
               ((t[3] - '0') * 10 + (t[4] - '0'));
    }
};