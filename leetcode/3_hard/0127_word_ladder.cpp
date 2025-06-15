#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int ladderLength(std::string beginWord, std::string endWord,
                     std::vector<std::string> &wordList) {
        std::unordered_set<std::string> words;
        for (auto &word : wordList) {
            words.insert(word);
        }

        if (words.count(endWord) == 0 || beginWord == endWord) {
            return 0;
        }

        int num_words = 1;
        std::queue<std::string> q;
        q.push(beginWord);
        while (q.empty() == false) {
            num_words++;

            size_t cnt = q.size();
            for (size_t i = 0; i < cnt; i++) {
                std::string curr = q.front();
                q.pop();
                for (char &c : curr) {
                    char orig = c;
                    for (char c2 = 'a'; c2 <= 'z'; c2++) {
                        if (c2 == orig) {
                            continue;
                        }
                        c = c2;
                        if (curr == endWord) {
                            return num_words;
                        } else if (words.count(curr)) {
                            words.erase(curr);
                            q.push(curr);
                        }
                    }
                    c = orig;
                }
            }
        }

        return 0;
    }
};
