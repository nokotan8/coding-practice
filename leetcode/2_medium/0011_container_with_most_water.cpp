#include <algorithm>
#include <vector>

class Solution {
  public:
    int maxArea(std::vector<int> &height) {
        int l = 0;
        int r = height.size() - 1;
        int max_area = 0;
        while (l < r) {
            max_area =
                std::max(max_area, (r - l) * std::min(height[l], height[r]));
            
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return max_area;
    }
};
