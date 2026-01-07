#include <cmath>
#include <string>

class Solution {
public:
    std::string intToRoman(int num) {
        if (num == 0) {
            return "";
        }

        int n = num;
        int order = 0;
        while (n >= 10) {
            n /= 10;
            order++;
        }

        std::string curr;
        if (n <= 3) {
            switch (order) {
                case 0:
                    curr = std::string(n, 'I');
                    break;
                case 1:
                    curr = std::string(n, 'X');
                    break;
                case 2:
                    curr = std::string(n, 'C');
                    break;
                case 3:
                    curr = std::string(n, 'M');
                    break;
                default:
                    curr = "";
                    break;
            }
            return curr + intToRoman(num - n * std::pow(10, order));
        } else if (n == 4) {
            switch (order) {
                case 0:
                    curr = "IV";
                    break;
                case 1:
                    curr = "XL";
                    break;
                case 2:
                    curr = "CD";
                    break;
                default:
                    curr = "";
                    break;
            }
            return curr + intToRoman(num - n * std::pow(10, order));
        } else if (n == 9) {
            switch (order) {
                case 0:
                    curr = "IX";
                    break;
                case 1:
                    curr = "XC";
                    break;
                case 2:
                    curr = "CM";
                    break;
                default:
                    curr = "";
                    break;
            }
            return curr + intToRoman(num - n * std::pow(10, order));
        } else {
            switch (order) {
                case 0:
                    curr = "V";
                    break;
                case 1:
                    curr = "L";
                    break;
                case 2:
                    curr = "D";
                    break;
                default:
                    curr = "";
                    break;
            }
            return curr + intToRoman(num - 5 * std::pow(10, order));
        }
    }
};
