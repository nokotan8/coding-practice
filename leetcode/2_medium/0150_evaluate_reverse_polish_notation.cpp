#include <stack>
#include <string>
#include <vector>

class Solution {
  public:
    int evalRPN(std::vector<std::string> &tokens) {
        std::stack<int> nums;
        for (std::string &token : tokens) {
            if (token.size() == 1) {
                switch (token[0]) {
                    case '+': {
                        int second = nums.top();
                        nums.pop();
                        int first = nums.top();
                        nums.pop();
                        nums.push(first + second);
                        break;
                    }
                    case '-': {
                        int second = nums.top();
                        nums.pop();
                        int first = nums.top();
                        nums.pop();
                        nums.push(first - second);
                        break;
                    }
                    case '*': {
                        int second = nums.top();
                        nums.pop();
                        int first = nums.top();
                        nums.pop();
                        nums.push(first * second);
                        break;
                    }
                    case '/': {
                        int second = nums.top();
                        nums.pop();
                        int first = nums.top();
                        nums.pop();
                        nums.push(first / second);
                        break;
                    }
                    default: {
                        nums.push(std::stoi(token));
                        break;
                    }
                }
            } else {
                nums.push(std::stoi(token));
            }
        }

        return nums.top();
    }
};
