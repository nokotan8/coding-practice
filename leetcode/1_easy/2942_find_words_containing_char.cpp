#include <string>
#include <vector>
class Solution {
  public:
    std::vector<int> findWordsContaining(std::vector<std::string> &words,
                                         char x) {
        std::vector<int> res;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                if (words[i][j] == x) {
                    res.push_back(i);
                    break;
                }

            }
        }

        return res;
    }
};
