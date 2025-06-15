#include <cstdlib>
#include <string>

class Solution {
  public:
    int maxDiff(int num) {
        std::string num_max = std::to_string(num);
        size_t idx1 = num_max.find_first_not_of('9');
        if (idx1 != num_max.npos) {
            char to_repl = num_max[idx1];
            for (char &c : num_max) {
                if (c == to_repl) {
                    c = '9';
                }
            }
        }

        std::string num_min = std::to_string(num);
        if (num_min[0] != '1') {
            char to_repl = num_min[0];
            for (char &c : num_min) {
                if (c == to_repl) {
                    c = '1';
                }
            }
        } else {
            for (size_t i = 1; i < num_min.size(); i++) {
                if (num_min[i] != '0' && num_min[i] != num_min[0]) {
                    char to_repl = num_min[i];
                    for (char &c : num_min) {
                        if (c == to_repl) {
                            c = '0';
                        }
                    }
                    break;
                }
            }
        }

        return std::stoi(num_max) - std::stoi(num_min);
    }
};
