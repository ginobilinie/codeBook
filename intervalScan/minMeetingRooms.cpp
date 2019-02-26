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
    // struct cmp{
    //   bool operator()(const Interval& v1, const Interval& v2) const
    //   {
    //         if (v1.start==v2.start) return v1.end<v2.end;
    //         return v1.start<v2.start;
    //   }
    // };
    static bool cmp(const Interval& v1, const Interval& v2)
    {
          if (v1.start==v2.start) return v1.end<v2.end;
            return v1.start<v2.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        /*we use a priority_queue to store the current maximum ending time of all necessary meeting conference rooms
           so we can do it in this way: when a new interval comes, and then we check if the top element of the pq is smaller than the interval's start value or not, if yes, we donot need to add a conference rooms, and we update the ending time of this room; if not, we have to push a new room which is represented by a new ending time.
        */
        sort(intervals.begin(),intervals.end(),cmp);
        priority_queue<int,vector<int>,greater<int>> pq;
        for (auto inter : intervals)
        {
            if (!pq.empty()&&pq.top()<=inter.start)//we just need to update the end time of the current room
            {
                pq.pop();
                pq.push(inter.end);
            }
            else//we have to add one new room
            {
                pq.push(inter.end);
            }
        }
        return pq.size();
    }
};
