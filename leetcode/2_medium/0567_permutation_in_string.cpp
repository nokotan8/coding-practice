/* Sliding window */
#include <string>
class Solution {
  public:
    bool check(int *letters1, int *letters2) {
        for (int i = 0; i < 26; i++)
            if (letters1[i] != letters2[i])
                return false;

        return true;
    }

    bool checkInclusion(std::string s1, std::string s2) {
        const size_t l1 = s1.size();
        const size_t l2 = s2.size();
        if (l1 > l2)
            return false;

        int letters1[26] = {0};
        int letters2[26] = {0};

        for (size_t i = 0; i < l1; i++) {
            letters2[s2[i] - 'a']++;
            letters1[s1[i] - 'a']++;
        }

        if (check(letters1, letters2))
            return true;

        for (size_t i = l1; i < l2; i++) {
            letters2[s2[i - l1] - 'a']--;
            letters2[s2[i] - 'a']++;

            if (check(letters1, letters2))
                return true;
        }

        return false;
    }
};
