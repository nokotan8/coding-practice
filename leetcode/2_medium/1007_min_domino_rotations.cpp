#include <algorithm>
#include <vector>
class Solution {
  public:
    int minDominoRotations(std::vector<int> &tops, std::vector<int> &bottoms) {
        int count[7] = {};
        for (int i = 0; i < tops.size(); i++) {
            count[tops[i]]++;
            if (tops[i] != bottoms[i]) {
                count[bottoms[i]]++;
            }
        }

        int n1 = 0;
        int n2 = 0;
        for (int i = 1; i < 7; i++) {
            if (count[i] == tops.size()) {
                for (int j = 0; j < tops.size(); j++) {
                    if (tops[j] == i) {
                        n1++;
                    }
                    if (bottoms[j] == i) {
                        n2++;
                    }
                }

                return tops.size() - std::max(n1, n2);
            }
        }

        return -1;
    }
};
