/* 2D Array */
#include <algorithm>
#include <string>
#include <vector>
class Solution {
  public:
    int longestPalindrome(std::vector<std::string> &words) {
        int res = 0;
        int freq[26][26] = {{0}};

        for (auto &word : words) {
            freq[word[0] - 'a'][word[1] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                res += std::min(freq[i][j], freq[j][i]) * 4;
            }
        }

        for (int i = 0; i < 26; i++) {
            res += (freq[i][i] / 2) * 4;
            if (res % 4 == 0 && freq[i][i] % 2 != 0) {
                res += 2;
            }
        }

        return res;
    }
};

/* Hash Map */
// #include <algorithm>
// #include <string>
// #include <unordered_map>
// #include <vector>
// class Solution {
//   public:
//     int longestPalindrome(std::vector<std::string> &words) {
//         int res = 0;
//         std::unordered_map<std::string, int> word_count;
//         for (std::string &word : words) {
//             word_count[word]++;
//         }
//
//         char rev[3];
//         for (auto &entry : word_count) {
//             int count;
//             rev[0] = entry.first[1];
//             rev[1] = entry.first[0];
//             if (entry.first[0] == entry.first[1]) {
//                 count = (entry.second / 2) * 2;
//                 res += count * 2;
//                 entry.second -= count;
//                 if (entry.second && res % 4 == 0) {
//                     entry.second--;
//                     res += 2;
//                 }
//             } else if (word_count.find(rev) != word_count.end() &&
//                        (count = std::min(entry.second, word_count[rev])) != 0) {
//                 res += count * 4;
//                 word_count[rev] -= count;
//                 word_count[entry.first] -= count;
//             }
//         }
//
//         return res;
//     }
// };
