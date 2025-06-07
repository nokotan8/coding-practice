#include <algorithm>
#include <iostream>
#include <vector>
class Solution {
  public:
    int numFriendRequests(std::vector<int> &ages) {
        int reqs = 0;
        std::sort(ages.begin(), ages.end());
        for (int age : ages) {
            if (age < 15)
                continue;
            int minAge = age / 2 + 7;
            int maxAge = age;

            int minI = binarySearch(ages, minAge);
            int maxI = binarySearch(ages, maxAge);

            reqs += std::max(0, maxI - minI - 1);
        }

        return reqs;
    }

    int binarySearch(std::vector<int> &arr, int target) {
        int lo = 0;
        int hi = arr.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] <= target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
