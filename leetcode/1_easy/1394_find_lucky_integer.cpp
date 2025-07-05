#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int findLucky(std::vector<int> &arr) {
        std::unordered_map<int, int> freq;

        for (int num : arr) {
            freq[num]++;
        }

        int lucky = -1;
        for (auto [n, f] : freq) {
            if (n == f) {
                lucky = std::max(lucky, n);
            }
        }

        return lucky;
    }
};

// #include <algorithm>
// #include <functional>
// #include <vector>
// class Solution {
//   public:
//     int findLucky(std::vector<int> &arr) {
//         std::sort(arr.begin(), arr.end(), std::greater<int>());
//
//         int freq = 1;
//         for (int i = 1; i < arr.size(); i++) {
//             if (arr[i] == arr[i - 1]) {
//                 freq++;
//             } else {
//                 if (freq == arr[i - 1]) {
//                     return freq;
//                 }
//                 freq = 1;
//             }
//         }
//         if (freq == arr.back()) {
//             return freq;
//         }
//
//         return -1;
//     }
// };
