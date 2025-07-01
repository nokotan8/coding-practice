#include <iterator>
#include <map>
#include <string>
#include <unordered_map>

class TimeMap {
  private:
    std::unordered_map<std::string, std::map<int, std::string>> time_map;

  public:
    TimeMap() {}

    void set(std::string key, std::string value, int timestamp) {
        time_map[key][timestamp] = value;
    }

    std::string get(std::string key, int timestamp) {
        if (time_map.find(key) == time_map.end()) {
            return "";
        }

        auto it = time_map[key].upper_bound(timestamp);
        if (it == time_map[key].begin()) {
            return "";
        } else {
            return std::prev(it)->second;
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * std::string param_2 = obj->get(key,timestamp);
 */
