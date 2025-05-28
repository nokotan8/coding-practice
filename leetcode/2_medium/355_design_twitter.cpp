#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Twitter {
  public:
    int curr_tweet;
    unordered_map<int, unordered_set<int>> followees;
    unordered_map<int, vector<pair<int, int>>> tweets;
    Twitter() : curr_tweet(1) {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({curr_tweet++, tweetId});
        // Less space but slower performance?
        // if (tweets[userId].size() > 10)
        //     tweets[userId].erase(tweets[userId].begin());
    }

    vector<int> getNewsFeed(int userId) {
        followees[userId].insert(userId);
        vector<int> res;
        // [0] = tweet index
        // [1] = userId
        // [2] = tweet index in tweets[userId]
        // [3] = tweetId
        priority_queue<vector<int>> pq;

        for (auto &f : followees[userId]) {
            if (tweets[f].size() == 0)
                continue;
            int i = tweets[f].size() - 1;
            auto &tweet = tweets[f][i];
            pq.push({tweet.first, f, i, tweet.second});
        }

        for (int i = 0; i < 10 && pq.size(); i++) {
            vector<int> top = pq.top();
            pq.pop();
            res.push_back(top[3]);
            int j = top[2] - 1;
            if (j >= 0) {
                auto &tweet = tweets[top[1]][j];
                pq.push({tweet.first, top[1], j, tweet.second});
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followees[followerId].count(followeeId))
            followees[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
