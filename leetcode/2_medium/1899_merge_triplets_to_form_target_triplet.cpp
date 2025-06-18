#include <vector>

class Solution {
  public:
    bool mergeTriplets(std::vector<std::vector<int>> &triplets,
                       std::vector<int> &target) {
        std::vector<bool> curr(3, false);
        for (auto &triplet : triplets) {
            bool use = false;
            for (int i = 0; i < 3; i++) {
                if (triplet[i] > target[i]) {
                    use = false;
                    break;
                } else if (triplet[i] == target[i]) {
                    use = true;
                }
            }

            if (use) {
                for (int i = 0; i < 3; i++) {
                    curr[i] = (curr[i] || triplet[i] == target[i]);
                }

                if (curr[0] && curr[1] && curr[2]) {
                    return true;
                }
            }
        }

        return false;
    }
};
