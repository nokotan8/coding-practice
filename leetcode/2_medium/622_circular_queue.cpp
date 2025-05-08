#include <vector>
class MyCircularQueue {
  public:
    std::vector<int> arr;
    int front = 0;
    int back = -1;
    int len = 0;

    MyCircularQueue(int k) { arr.resize(k); }

    bool enQueue(int value) {
        if (!isFull()) {
            back = (back + 1) % arr.size();
            arr[back] = value;
            len++;
            return true;
        } else {
            return false;
        }
    }

    bool deQueue() {
        if (!isEmpty()) {
            front = (front + 1) % arr.size();
            len--;
            return true;
        } else {
            return false;
        }
    }

    int Front() { return isEmpty() ? -1 : arr[front]; }

    int Rear() { return isEmpty() ? -1 : arr[back]; }

    bool isEmpty() { return len == 0; }

    bool isFull() { return len == arr.size(); }
};
