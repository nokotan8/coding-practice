#include <algorithm>
#include <cstdlib>
#include <string>
#include <utility>
#include <vector>

class Solution {
  public:
    std::vector<std::pair<char, char>> directions = {
        {'N', 'E'}, {'N', 'W'}, {'S', 'E'}, {'S', 'W'}};

    int maxDistance(std::string s, int k) {
        int max_dist = 0;

        for (auto &dir : directions) {
            int x = 0, y = 0;
            int changes = 0;
            for (char c : s) {
                if (changes < k && c != dir.first && c != dir.second) {
                    changes++;
                    switch (c) {
                        case 'N':
                            y--;
                            break;
                        case 'S':
                            y++;
                            break;
                        case 'E':
                            x--;
                            break;
                        case 'W':
                            x++;
                            break;
                    }
                } else {
                    switch (c) {
                        case 'N':
                            y++;
                            break;
                        case 'S':
                            y--;
                            break;
                        case 'E':
                            x++;
                            break;
                        case 'W':
                            x--;
                            break;
                    }
                }
                max_dist = std::max(max_dist, abs(x) + abs(y));
            }
        }

        return max_dist;
    }
};
