#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumDistance(vector<int>& nums) {
    std::unordered_map<int, std::vector<int>> m;
    for (int i = 0; i < nums.size(); ++i) {
      m[nums[i]].push_back(i);
    }
    int res = std::numeric_limits<int>::max();
    for (const auto& kv : m) {
      if (kv.second.size() < 3) {
        continue;
      }
      for (int i = 0; i < kv.second.size(); ++i) {
        for (int j = i + 1; j < kv.second.size(); ++j) {
          for (int k = j + 1; k < kv.second.size(); ++k) {

            int dist = std::abs(kv.second[i] - kv.second[j]) +
                       std::abs(kv.second[j] - kv.second[k]) +
                       std::abs(kv.second[k] - kv.second[i]);
            res = std::min(res, dist);
          }
        }
      }
    }
    if (res == std::numeric_limits<int>::max()) {
      return -1;
    }
    return res;
  }
};

int main() {
  Solution sl;
  std::vector<int> nums = {1, 2, 1, 1, 3};
  int res = sl.minimumDistance(nums);
  std::cout << res << std::endl;
}