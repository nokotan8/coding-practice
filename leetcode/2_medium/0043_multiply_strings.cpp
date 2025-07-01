#include <algorithm>
#include <string>

class Solution {
    std::string add(std::string &num1, std::string &num2) {
        if (num1.size() < num2.size()) {
            return add(num2, num1);
        }
        std::string res = "";

        int carry = 0;
        int diff = num1.size() - num2.size();
        for (int j = num2.size() - 1; j >= 0; j--) {
            int col = (num2[j] - '0') + (num1[j + diff] - '0') + carry;
            carry = col / 10;
            res += ((col % 10) + '0');
        }
        for (int i = diff - 1; i >= 0; i--) {
            int col = (num1[i] - '0') + carry;
            carry = col / 10;
            res += ((col % 10) + '0');
        }
        if (carry != 0) {
            res += (carry + '0');
        }

        std::reverse(res.begin(), res.end());
        return res;
    }

  public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        } else if (num1.size() < num2.size()) {
            return multiply(num2, num1);
        }
        std::string res = "";

        for (int j = num2.size() - 1; j >= 0; j--) {
            std::string curr = "";
            int carry = 0;
            for (int i = num1.size() - 1; i >= 0; i--) {
                int col = (num1[i] - '0') * (num2[j] - '0') + carry;
                carry = col / 10;
                curr += ((col % 10) + '0');
            }
            if (carry != 0) {
                curr += (carry + '0');
            }
            std::reverse(curr.begin(), curr.end());
            curr += std::string(num2.size() - j - 1, '0');
            res = add(res, curr);
        }

        return res;
    }
};
