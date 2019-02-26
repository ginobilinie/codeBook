1. minMeetingRooms.cpp: 
problem: 给一些开会的时间段，问下到底要多少个会议室才能安排得过来.
Solution: we use a priority_queue to store the current maximum ending time of all necessary meeting conference rooms
so we can do it in this way: when a new interval comes, and then we check if the top element of the pq is smaller than the interval's 
start value or not, if yes, we donot need to add a conference rooms, and we update the ending time of this room; 
if not, we have to push a new room which is represented by a new ending time.
