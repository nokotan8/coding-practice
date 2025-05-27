#include <functional>
#include <queue>
#include <vector>
class KthLargest {
  public:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    KthLargest(int k, std::vector<int> &nums) : k(k) {
        for (int num : nums)
            pq.push(num);
        while (pq.size() > k)
            pq.pop();
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
        int res = pq.top();
        return res;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
