#include <algorithm>
#include <string>
#include <unordered_map>
using std::string;

class Solution {
  public:
    string lastNonEmptyString(string s) {
        int max = 0;
        std::unordered_map<char, int> char_count;
        for (char c : s) {
            char_count[c]++;
            max = std::max(max, char_count[c]);
        }

        string res = "";
        for (int i = s.size(); i >= 0; i--) {
            if (char_count[s[i]] == max) {
                res = s[i] + res;
                char_count[s[i]]--;
            } 
        }

        return res;
    }
};
