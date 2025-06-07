#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<char, std::vector<char>> chars = {
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}}
};
class Solution {
  public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.size() == 0)
            return {};

        std::vector<std::string> res;
        combs(digits, 0, "", res);

        return res;
    }

    void combs(std::string &digits, int index, std::string curr, std::vector<std::string> &res) {
        if (index == digits.size()) {
            res.push_back(curr);
            return;
        }
        for (char c : chars[digits[index]]) {
            combs(digits, index + 1, curr + c, res);
        }

        return;
    }
};
