#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
  private:
    std::unordered_set<int> powers;
    int len;

    bool backtrack(std::string &curr, std::unordered_map<char, int> &freq,
                   int rem) {
        if (rem == 0) {
            return powers.count(std::stoi(curr)) == 1;
        }

        for (auto &[c, f] : freq) {
            if (f > 0 && ((len == rem && c != '0') || rem != len)) {
                f--;
                curr.push_back(c);

                if (backtrack(curr, freq, rem - 1)) {
                    return true;
                }

                curr.pop_back();
                f++;
            }
        }

        return false;
    }

  public:
    bool reorderedPowerOf2(int n) {
        for (int i = 0, p = 1; i < 30; i++, p *= 2) {
            powers.insert(p);
        }

        std::unordered_map<char, int> freq;
        std::string n_str = std::to_string(n);
        len = n_str.size();

        for (char c : n_str) {
            freq[c]++;
        }

        std::string curr = "";
        return backtrack(curr, freq, n_str.size());
    }
};
