
// Definition of Interval:
#include <algorithm>
#include <vector>
class Interval {
  public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
  public:
    bool canAttendMeetings(std::vector<Interval> &intervals) {
        if (intervals.size() < 2) {
            return true;
        }

        std::sort(intervals.begin(), intervals.end(),
                  [](Interval &a, Interval &b) { return a.start < b.start; });

        int end = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < end) {
                return false;
            }
            end = intervals[i].end;
        }

        return true;
    }
};
