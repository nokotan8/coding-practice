#include <algorithm>
#include <stack>
#include <string>
#include <utility>

class Solution {
  public:
    int maximumGain(std::string s, int x, int y) {
        std::stack<char> st;
        int gain = std::max(x, y);
        int score = 0;
        char c1 = x > y ? 'a' : 'b';
        char c2 = x > y ? 'b' : 'a';

        for (char c : s) {
            if (st.size() && st.top() == c1 && c == c2) {
                score += gain;
                st.pop();
            } else {
                st.push(c);
            }
        }
        std::swap(c1, c2);
        gain = std::min(x, y);
        s = "";
        while (st.size()) {
            s.push_back(st.top());
            st.pop();
        }
        std::reverse(s.begin(), s.end());
        for (char c : s) {
            if (st.size() && st.top() == c1 && c == c2) {
                score += gain;
                st.pop();
            } else {
                st.push(c);
            }
        }

        return score;
    }
};
