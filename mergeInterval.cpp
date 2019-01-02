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
    static bool cmp(struct Interval i1, struct Interval i2)
    {
        if (i1.start==i2.start)
        {
            return i1.end<i2.end;
        }
        return i1.start<i2.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(), cmp);
        int sz = intervals.size();
        if (sz<=1)
            return intervals;
        Interval node1 = intervals[0];
        Interval node2;
        int cnt = 0;
        vector<Interval> res;
        res.push_back(node1);
        cnt++;
        for (int i=1; i<sz; i++)
        {
            node1 = res[cnt-1];
            res.pop_back();
            cnt--;
            node2 = intervals[i];
            if (node1.end>=node2.start)
            {
                node2.start = node1.start;
                if (node1.end>node2.end)
                    node2.end = node1.end;
                res.push_back(node2);
                cnt++;
            }
            else
            {
                res.push_back(node1);
                res.push_back(node2);
                cnt++;
                cnt++;
            }
            // res.push_back(node2);
            // node1 = node2;
        }
        return res;
    }
};
