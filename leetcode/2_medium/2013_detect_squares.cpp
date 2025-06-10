#include <cstdlib>
#include <unordered_map>
#include <vector>

class DetectSquares {
  public:
    DetectSquares() {}

    void add(std::vector<int> point) {
        point_freq[point_to_key(point[0], point[1])]++;
        points.push_back(point);
    }

    int count(std::vector<int> point) {
        int res = 0;
        for (auto &p : points) {
            int p_x = p[0];
            int p_y = p[1];
            if (std::abs(point[0] - p_x) == std::abs(point[1] - p_y) &&
                point[0] != p_x) {
                res += point_freq[point_to_key(point[0], p_y)] *
                       point_freq[point_to_key(p_x, point[1])];
            }
        }

        return res;
    }

  private:
    std::unordered_map<long, int> point_freq;
    std::vector<std::vector<int>> points;

    long point_to_key(int x, int y) {
        return ((long)y << 32) | (long)x;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
