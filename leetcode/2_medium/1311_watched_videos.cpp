#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
class Solution {
  public:
    static bool compareVideo(std::pair<std::string, int> &a,
                             std::pair<std::string, int> &b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    }
    std::vector<std::string>
    watchedVideosByFriends(std::vector<std::vector<std::string>> &watchedVideos,
                           std::vector<std::vector<int>> &friends, int id,
                           int level) {
        std::queue<int> queue;
        queue.push(id);
        std::unordered_set<int> visited;
        visited.insert(id);

        for (int i = 0; i < level; i++) {
            const int qsize = queue.size();
            for (int j = 0; j < qsize; j++) {
                int curr = queue.front();
                queue.pop();
                for (int f : friends[curr]) {
                    if (visited.count(f))
                        continue;
                    visited.insert(f);
                    queue.push(f);
                }
            }
        }

        std::unordered_map<std::string, int> watched;
        while (!queue.empty()) {
            int curr = queue.front();
            queue.pop();
            for (auto v : watchedVideos[curr]) {
                watched[v]++;
            }
        }

        std::vector<std::pair<std::string, int>> res;
        for (auto i = watched.begin(); i != watched.end(); i++) {
            res.push_back({i->first, i->second});
        }

        sort(res.begin(), res.end(), compareVideo);
        std::vector<std::string> ans;
        for (auto &v : res) {
            ans.push_back(v.first);
        }

        return ans;
    }
};
