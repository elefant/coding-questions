/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> mergedIntervals;
        for (auto itv: intervals) {
            insertInterval(mergedIntervals, itv);
        }
        return mergedIntervals;
    }

    void insertInterval(vector<Interval>& intervals, // non-overlapped intervals
                        Interval toInsert) {
        vector<Interval> ret;
        for (auto itv: intervals) {
            // itv: the remaining earliest interval.
            if (toInsert.end < itv.start) {
                // |toInsert| ends earlier than the earlies remaining interval:
                //   ==> Insert |toInsert| and let |toInsert| be itv.
                ret.push_back(toInsert);
                toInsert.start = itv.start;
                toInsert.end = itv.end;
            } else if (toInsert.start > itv.end) {
                // |toInsert| starts later than the earlies remaining interval:
                //   ==> Simply insert itv.
                ret.push_back(itv);
            } else {
                // Merge itv to |toInsert|
                Interval merged(min(toInsert.start, itv.start), max(toInsert.end, itv.end));
                toInsert = merged;
            }
        }
        ret.push_back(toInsert);
        intervals = move(ret);
    }
};

///////////////////////////////

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            return a.start < b.start;
        });
        vector<Interval> sol;
        sol.push_back(intervals[0]);
        int curEnd = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start > curEnd) {
                sol.push_back(intervals[i]);
                curEnd = intervals[i].end;
            } else {
                curEnd = max(curEnd, intervals[i].end);
                sol.back().end = curEnd;
            }
        }
        return sol;
    }
};