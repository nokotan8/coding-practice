#include <queue>
#include <unordered_set>
#include <vector>
class Solution {
  public:
    int maxCandies(std::vector<int> &status, std::vector<int> &candies,
                   std::vector<std::vector<int>> &keys,
                   std::vector<std::vector<int>> &containedBoxes,
                   std::vector<int> &initialBoxes) {
        int max_candy = 0;

        std::queue<int> boxes;
        std::unordered_set<int> opened_boxes;
        std::unordered_set<int> avail_boxes;
        for (int b : initialBoxes) {
            avail_boxes.insert(b);
            if (status[b]) {
                boxes.push(b);
                opened_boxes.insert(b);
            }
        }

        while (boxes.empty() == false) {
            int box = boxes.front();
            boxes.pop();
            max_candy += candies[box];

            for (int b : containedBoxes[box]) {
                avail_boxes.insert(b);
                if (opened_boxes.count(b) == 0 && status[b]) {
                    opened_boxes.insert(b);
                    boxes.push(b);
                }
            }

            for (int k : keys[box]) {
                status[k] = 1;
                if (opened_boxes.count(k) == 0 && avail_boxes.count(k)) {
                    opened_boxes.insert(k);
                    boxes.push(k);
                }
            }
        }

        return max_candy;
    }
};
