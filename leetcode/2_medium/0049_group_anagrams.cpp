#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
class Solution {
  public:
    std::vector<std::vector<std::string>>
    groupAnagrams(std::vector<std::string> &strs) {
        std::vector<std::vector<std::string>> res;
        std::unordered_map<std::string, std::vector<std::string>> anagrams;

        int curr_index = 0;
        for (std::string &str : strs) {
            std::string key = str;
            std::sort(key.begin(), key.end());

            anagrams[key].push_back(str);
        }

        for (auto &entry : anagrams) {
            res.push_back(entry.second);
        }

        return res;
    }
};
