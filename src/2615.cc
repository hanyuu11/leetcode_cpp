#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<long long> distance(vector<int>& nums) {
    using ll = long long;
    std::unordered_map<int, std::vector<int>> groups;
    const int n = nums.size();
    for (int i = 0; i < n; ++i) {
      groups[nums[i]].push_back(i);
    }
    std::vector<ll> res(n);
    for (const auto& p : groups) {
      const auto& group = p.second;
      ll total = std::accumulate(group.begin(), group.end(), 0LL);
      ll prefix_total = 0;
      for (int i = 0; i < group.size(); ++i) {
        res[group[i]] =
            total - prefix_total * 2 + group[i] * (2 * i - group.size());
        prefix_total += group[i];
      }
    }
    return res;
  }
};

int main() {
  Solution sl;
  std::vector<int> nums = {1, 3, 1, 1, 2};
  auto res = sl.distance(nums);
  for (const long long r : res) {
    std::cout << r << ", ";
  }
}
