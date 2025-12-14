#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int task_count[26] = {0};
        for (auto task : tasks) {
            task_count[task - 'A']++;
        }

        struct comp {
            bool operator()(pair<int, char> &a, pair<int, char> &b) {
                return a.first < b.first;
            }
        };
        priority_queue<pair<int, char>, vector<pair<int, char>>, comp> pq;
        for (int i = 0; i < 26; i++) {
            if (task_count[i] > 0) {
                pq.push({task_count[i], i + 'A'});
            }
        }

        queue<pair<char, int>> cooldown;
        int time = 0;
        while (pq.empty() == false || cooldown.empty() == false) {
            if (cooldown.empty() == false && cooldown.front().second == time) {
                char c = cooldown.front().first;
                cooldown.pop();
                pq.push({task_count[c - 'A'], c});
            }

            if (pq.empty() == false) {
                char c = pq.top().second;
                pq.pop();
                task_count[c - 'A']--;
                if (task_count[c - 'A'] != 0) {
                    cooldown.push({c, time + n + 1});
                }
            } else {
                time = cooldown.front().second - 1;
            }

            time++;
        }

        return time;
    }
};
