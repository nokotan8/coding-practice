#include <map>
#include <unordered_map>
#include <vector>

class FindSumPairs {
  private:
    std::unordered_map<int, int> nums2_freq;
    std::map<int, int> nums1_freq;
    std::vector<int> nums2;

  public:
    FindSumPairs(std::vector<int> &nums1, std::vector<int> &nums2)
        : nums2(nums2) {
        for (int num : nums1) {
            nums1_freq[num]++;
        }

        for (int num : nums2) {
            nums2_freq[num]++;
        }
    }

    void add(int index, int val) {
        nums2_freq[nums2[index]]--;
        nums2[index] += val;
        nums2_freq[nums2[index]]++;
    }

    int count(int tot) {
        int res = 0;
        for (auto [num, freq] : nums1_freq) {
            if (num >= tot) {
                break;
            }
            if (nums2_freq.count(tot - num)) {
                res += freq * nums2_freq[tot - num];
            }
        }

        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
