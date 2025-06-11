/* O(max_element(nums) - min_element(nums)) bucket sort */
#include <algorithm>
#include <climits>
#include <vector>

class Solution {
  public:
    int findKthLargest(std::vector<int> &nums, int k) {
        int nums_min = INT_MAX;
        int nums_max = INT_MIN;

        for (int num : nums) {
            nums_min = std::min(nums_min, num);
            nums_max = std::max(nums_max, num);
        }

        int num_range = nums_max - nums_min + 1;

        std::vector<int> freq(num_range, 0);

        for (int num : nums) {
            freq[num - nums_min]++;
        }

        int pos = 0;
        for (int i = (int)freq.size() - 1; i >= 0; i--) {
            pos += freq[i];
            if (pos >= k) {
                return i + nums_min;
            }
        }

        return 0;
    }
};

/* O(nlog(k)) PQ */
// #include <functional>
// #include <queue>
// #include <vector>
//
// class Solution {
// public:
//     int findKthLargest(std::vector<int>& nums, int k) {
//         std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
//
//         for (int num : nums) {
//             pq.push(num);
//
//             if (pq.size() > k) {
//                 pq.pop();
//             }
//         }
//
//         return pq.top();
//     }
// };
