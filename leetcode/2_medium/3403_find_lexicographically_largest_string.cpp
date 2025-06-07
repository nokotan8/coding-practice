/* Still O(n^2) but better on average */
#include <algorithm>
#include <string>
#include <vector>
class Solution {
  public:
    std::string answerString(std::string word, int numFriends) {
        if (numFriends == 1)
            return word;

        size_t n = word.size();
        size_t max_str_len = word.size() - (size_t)numFriends + 1;

        // Largest string must start from largest char
        std::vector<size_t> max_idxs = {0};
        char max_char = word[0];
        for (size_t i = 1; i < n; i++) {
            if (word[i] > max_char) {
                max_idxs.clear();
                max_idxs.push_back(i);
                max_char = word[i];
            } else if (word[i] == max_char) {
                max_idxs.push_back(i);
            }
        }

        std::string res = "";
        for (size_t idx : max_idxs) {
            res = std::max(res,
                           word.substr(idx, std::min(max_str_len, n - idx)));
        }

        return res;
    }
};

/* Brute force */
// #include <algorithm>
// #include <string>
// class Solution {
//   public:
//     std::string answerString(std::string word, int numFriends) {
//         if (numFriends == 1)
//             return word;
//         size_t n = word.size();
//
//         size_t max_str_size = word.size() - (size_t)numFriends + 1;
//         std::string res = "";
//
//         for (int i = 0; i < n; i++) {
//             res = std::max(res, word.substr(i, std::min(max_str_size, n - i)));
//         }
//
//         return res;
//     }
// };
