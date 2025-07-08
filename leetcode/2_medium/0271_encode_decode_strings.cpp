#include <string>
#include <vector>

class Solution {
  public:
    std::string encode(std::vector<std::string> &strs) {
        std::string res = "";
        for (std::string &s : strs) {
            res += std::to_string(s.size()) + "#" + s;
        }

        return res;
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> res;
        const int n = s.size();

        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && s[j] != '#')
                j++;
            if (j == n)
                break;

            int count = std::stoi(s.substr(i, j - i));
            if (j + count >= n)
                break;

            res.push_back(s.substr(j + 1, count));
            i = j + count + 1;
        }

        return res;
    }
};
