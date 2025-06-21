#include <algorithm>
#include <string>

class Solution {
  public:
    int minimumDeletions(std::string word, int k) {
        int freq[26] = {0};
        for (char c : word) {
            freq[c - 'a']++;
        }

        int min_del = word.size() + 1;
        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                int curr_del = 0;
                for (int j = 0; j < 26; j++) {
                    if (i == j)
                        continue;
                    if (freq[j] > freq[i] + k) {
                        curr_del += freq[j] - freq[i] - k;
                    } else if (freq[j] && freq[j] < freq[i]) {
                        curr_del += freq[j];
                    }
                }
                min_del = std::min(min_del, curr_del);
            }
        }

        return min_del;
    }
};
