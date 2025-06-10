#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
        std::vector<std::vector<int>> buckets(nums.size() + 1);
        std::unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        for (auto [num, fq] : freq) {
            buckets[fq].push_back(num);
        }

        size_t offset = 0;
        int i = (int)nums.size();
        std::vector<int> res(k);
        while (offset < k) {
            for (; i >= 0 && buckets[i].size() == 0; i--) {
            }

            for (int num : buckets[i]) {
                res[offset++] = num;
            }

            i--;
        }

        return res;
    }
};

// #include <functional>
// #include <queue>
// #include <unordered_map>
// #include <utility>
// #include <vector>
//
// class Solution {
//   public:
//     std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
//         std::unordered_map<int, int> freq;
//         std::priority_queue<std::pair<int, int>,
//                             std::vector<std::pair<int, int>>,
//                             std::greater<std::pair<int, int>>>
//             pq;
//
//         for (int num : nums) {
//             freq[num]++;
//         }
//
//         for (auto f : freq) {
//             pq.push({f.second, f.first});
//
//             if (pq.size() > k) {
//                 pq.pop();
//             }
//         }
//
//         std::vector<int> res;
//         while (pq.empty() == false) {
//             res.push_back(pq.top().second);
//             pq.pop();
//         }
//
//         return res;
//     }
// };
