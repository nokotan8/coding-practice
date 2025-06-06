#include <algorithm>
#include <stack>
#include <string>

class Solution {
  public:
    std::string robotWithString(std::string s) {
        std::string res;
        std::stack<char> t;
        int freq[26] = {0};
        char min_char = '{'; // one more than 'z'
        int s_idx = 0;

        for (char c : s) {
            freq[c - 'a']++;
            min_char = std::min(min_char, c);
        }

        while (s_idx < s.size()) {
            t.push(s[s_idx]);
            freq[s[s_idx] - 'a']--;
            s_idx++;
            // Update to smallest remaining char in s
            while (min_char != '{' && freq[min_char - 'a'] == 0)
                min_char++;

            while (t.empty() == false && t.top() <= min_char) {
                res.push_back(t.top());
                t.pop();
            }
        }

        return res;
    }
};
