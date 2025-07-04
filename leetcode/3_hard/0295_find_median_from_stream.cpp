#include <functional>
#include <queue>
#include <vector>

class MedianFinder {
  private:
    std::priority_queue<int, std::vector<int>, std::less<int>> lower;
    std::priority_queue<int, std::vector<int>, std::greater<int>> upper;

  public:
    MedianFinder() {}

    void addNum(int num) {
        if (lower.empty() == false && num <= lower.top()) {
            lower.push(num);
        } else if (upper.empty() == false && num >= upper.top()) {
            upper.push(num);
        } else {
            lower.push(num);
        }

        if (lower.size() > upper.size() + 1) {
            upper.push(lower.top());
            lower.pop();
        }
        if (upper.size() > lower.size()) {
            lower.push(upper.top());
            upper.pop();
        }
    }

    double findMedian() {
        if ((lower.size() + upper.size()) & 1) {
            return lower.top();
        } else {
            return (lower.top() + upper.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
