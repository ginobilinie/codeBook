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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if (intervals.emtpy())
        {
            res.push_back(newInterval);
            return res;
        }
        int sz = intervals.size();
        int ind = biSearch(intervals, newInterval);//ind's value is <= the target value

        // insert
        Interval node1 = intervals[i];
        if (newInterval.start<=node1.end)
        {
            if (node1.end<newInterval.end)
                intervals[i].end = newInterval.end;
        }else
        {
            if (newInterval.end<)   
        }

        //adjust the vector
        
    }
    int biSearch(vector<Interval>& intervals, Interval newInterval)
    {
        int sz = intervals.size();
        int l=0, r=sz-1, mid;
        while(l<=r)
        {
            mid = (l+r)/2;
            if (intervals[mid].start==newInterval.start)
            {
                break;
            }
            else if (intervals[mid].start<newInterval.start)
            {
                l = mid + 1;
            }else
            {
                r = mid - 1;
            }
        }
        if (intervals[mid].start>newInterval.start && mid>0)
            mid = mid -1;
        return mid; //we return the first one whose value is less or equal to the target value
    }
};
