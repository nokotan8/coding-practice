#include <algorithm>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<std::string>
    findItinerary(std::vector<std::vector<std::string>> &tickets) {
        std::unordered_map<std::string, std::vector<std::string>> graph;
        for (auto &ticket : tickets) {
            graph[ticket[0]].push_back(ticket[1]);
        }
        for (auto &[node, adj] : graph) {
            std::sort(adj.begin(), adj.end(), std::greater<std::string>());
        }

        // Hierholzer's algorithm:
        // https://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph
        std::vector<std::string> circuit;
        std::vector<std::string> curr_path = {"JFK"};

        while (curr_path.empty() == false) {
            std::string curr = curr_path.back();

            if (graph[curr].empty() == false) {
                curr_path.push_back(graph[curr].back());
                graph[curr].pop_back();
            } else {
                circuit.push_back(curr_path.back());
                curr_path.pop_back();
            }
        }

        std::reverse(circuit.begin(), circuit.end());
        return circuit;
    }
};
