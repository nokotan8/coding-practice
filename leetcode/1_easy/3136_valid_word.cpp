#include <cctype>
#include <string>
#include <unordered_set>

class Solution {
  public:
    bool isValid(std::string word) {
        if (word.size() < 3) {
            return false;
        }
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        bool vowel = false;
        bool cons = false;
        for (char c : word) {
            c = std::tolower(c);
            if (std::isalpha(c)) {
                if (vowels.count(c)) {
                    vowel = true;
                } else {
                    cons = true;
                }
            } else if (!std::isdigit(c)) {
                return false;
            }
        }

        return vowel && cons;
    }
};
