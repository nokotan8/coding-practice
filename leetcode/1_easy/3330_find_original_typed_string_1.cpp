#include <string>

class Solution {
  public:
    int possibleStringCount(std::string word) {
        int res = 1;

        for (int i = 0; i < word.size(); i++) {
            int j = i + 1;
            int count = 0;
            while (j < word.size() && word[j] == word[i]) {
                count++;
                j++;
            }
            i = j - 1;
            res += count;
        }

        return res;
    }
};
