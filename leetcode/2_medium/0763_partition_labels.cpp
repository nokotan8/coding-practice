#include <algorithm>
#include <string>
#include <utility>
#include <vector>

class Solution {
  public:
    std::vector<int> partitionLabels(std::string s) {
        int first[26] = {-1};
        int last[26] = {0};
        for (int i = 0; i < 26; i++) {
            first[i] = -1;
        }

        for (int i = 0; i < (int)s.size(); i++) {
            last[s[i] - 'a'] = i;
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
        }

        std::vector<std::pair<int, int>> positions;
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1) {
                positions.push_back({first[i], last[i]});
            }
        }

        std::sort(positions.begin(), positions.end());
        std::vector<int> res;
        for (int i = 0; i < positions.size();) {
            auto [first_pos, last_pos] = positions[i];
            int j = i + 1;
            for (; j < positions.size(); j++) {
                if (positions[j].first > last_pos) {
                    break;
                }
                last_pos = std::max(last_pos, positions[j].second);
            }
            res.push_back(last_pos - first_pos + 1);
            i = j;
        }

        return res;
    }
};
