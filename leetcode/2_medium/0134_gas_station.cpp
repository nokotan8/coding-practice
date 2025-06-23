#include <vector>

class Solution {
  public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
        const size_t n = gas.size();

        int gas_amt = 0;
        int total_cost = 0;
        for (size_t i = 0; i < n; i++) {
            gas_amt += gas[i];
            total_cost += cost[i];
        }
        if (gas_amt < total_cost) {
            return -1;
        }

        int curr_gas = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            curr_gas += (gas[i] - cost[i]);

            if (curr_gas < 0) {
                curr_gas = 0;
                res = i + 1;
            }
        }

        return res;
    }
};
