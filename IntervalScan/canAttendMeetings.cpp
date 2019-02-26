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
    static bool cmp(const Interval& v1, const Interval& v2)
    {
        if (v1.start==v2.start) return v1.end<v2.end;
        return v1.start<v2.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        //if there is an overlap, then we should return false
        if (intervals.empty())
            return 1;
        sort(intervals.begin(),intervals.end(),cmp);
        int sz = intervals.size();
        if (sz==1)
            return 1;
        auto prev = intervals[0];
        for (int i=1; i<sz; i++)
        {
            auto curr = intervals[i];
            if (prev.end>curr.start)
                return 0;
            else
            {
                prev = curr;
            }
        }
        return 1;
    }
};
