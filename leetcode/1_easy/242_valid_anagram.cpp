/* Hash map */
#include <string>
#include <unordered_map>
class Solution {
  public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size())
            return false;

        std::unordered_map<char, int> map1;
        std::unordered_map<char, int> map2;

        for (size_t i = 0; i < s.size(); i++) {
            map1[s[i]]++;
            map2[t[i]]++;
        }

        return map1 == map2;
    }
};

/* Sorting */
// #include <algorithm>
// #include <string>
// class Solution {
//   public:
//     bool isAnagram(std::string s, std::string t) {
//         if (s.size() != t.size())
//             return false;
//         std::sort(s.begin(), s.end());
//         std::sort(t.begin(), t.end());
//
//         return s == t;
//     }
// };
