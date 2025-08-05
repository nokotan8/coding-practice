#include <vector>

class Solution {
  public:
    int numOfUnplacedFruits(std::vector<int> &fruits,
                            std::vector<int> &baskets) {
        const int n = fruits.size();
        int res = 0;

        for (int &fruit : fruits) {
            for (int &basket : baskets) {
                if (basket >= fruit) {
                    fruit = 0;
                    basket = 0;
                    break;
                }
            }

            if (fruit != 0) {
                res++;
            }
        }

        return res;
    }
};
