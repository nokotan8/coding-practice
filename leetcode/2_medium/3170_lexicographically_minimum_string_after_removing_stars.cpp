#include <queue>
#include <string>
#include <utility>
#include <vector>
class Solution {
  public:
    std::string clearStars(std::string s) {
        // In pq, smallest chars come first but if chars equal, largest index
        // comes first
        auto comp = [](std::pair<char, size_t> a, std::pair<char, size_t> b) {
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        };

        std::priority_queue<std::pair<char, size_t>,
                            std::vector<std::pair<char, size_t>>,
                            decltype(comp)>
            pq(comp);

        int num_stars = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                num_stars++;
                auto [_, idx] = pq.top();
                pq.pop();
                s[idx] = '*';
            } else {
                pq.push({s[i], i});
            }
        }

        // For each '*', result string has no '*' and
        // one less removed character
        std::string res(s.size() - num_stars * 2, '\0');
        for (size_t i = 0, j = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                res[j++] = s[i];
            }
        }

        return res;
    }
};
