#include <vector>
class Solution {
  public:
    std::vector<int> findArray(std::vector<int> &pref) {
        std::vector<int> arr(pref.size());
        arr[0] = pref[0];
        for (int i = 1; i < pref.size(); i++) {
            arr[i] = pref[i - 1] ^ pref[i];
        }

        return arr;
    }
};
