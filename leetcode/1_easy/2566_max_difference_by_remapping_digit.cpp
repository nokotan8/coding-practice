/* Without string conversion! */
class Solution {
  public:
    int minMaxDifference(int num) {
        int digit1 = -1;
        for (int num1 = num; num1 != 0; num1 /= 10) {
            int mod = num1 % 10;
            if (mod != 9) {
                digit1 = mod;
            }
        }

        int digit2 = -1;
        for (int num2 = num; num2 != 0; num2 /= 10) {
            if (num2 < 10) {
                digit2 = num2;
            }
        }

        int add = 0;
        if (digit1 != -1) {
            for (int tens = 1, num1 = num; num1 != 0; num1 /= 10, tens *= 10) {
                if (num1 % 10 == digit1) {
                    add += tens * (9 - digit1);
                }
            }
        }

        int subt = 0;
        if (digit2 != -1) {
            for (int tens = 1, num2 = num; num2 != 0; num2 /= 10, tens *= 10) {
                if (num2 % 10 == digit2) {
                    subt += tens * digit2;
                }
            }
        }

        return add + subt; // (num + add) - (num - subt)
    }
};
