#include <vector>

class Solution {
  public:
    std::vector<int> plusOne(std::vector<int> &digits) {

        bool carry = false;
        if (digits.back() == 9) {
            digits.back() = 0;
            carry = true;
        } else {
            digits.back()++;
        }

        for (int i = digits.size() - 2; i >= 0 && carry; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                carry = false;
            }
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
