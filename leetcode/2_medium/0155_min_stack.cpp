#include <algorithm>
#include <stack>
#include <utility>

class MinStack {
  private:
    std::stack<std::pair<int, int>> stk;

  public:
    MinStack() {}

    void push(int val) {
        if (stk.empty()) {
            stk.emplace(val, val);
        } else {
            int currMin = stk.top().second;
            stk.emplace(val, std::min(currMin, val));
        }
    }

    void pop() {
        stk.pop();
    }

    int top() {
        return stk.top().first;
    }

    int getMin() {
        return stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
