#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<vector<int>>& grid, int x) {
    std::vector<int> nums;
    nums.reserve(grid.size() * grid[0].size());

    for (const auto& v : grid) {
      for (const int n : v) {
        if ((n - grid[0][0]) % x != 0) {
          return -1;
        }
        nums.push_back(n);
      }
    }

    std::sort(nums.begin(), nums.end());
    int choose = nums[nums.size() / 2];
    int ans = std::accumulate(
        nums.begin(), nums.end(), 0,
        [choose, x](int acc, int n) { return acc + std::abs(n - choose) / x; });
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution sl;
  std::vector<std::vector<int>> grid = {
    {2, 4},
    {6, 8}
  };
  int x = 2;
  int ans = sl.minOperations(grid, x);
  std::cout << ans << std::endl;
  return 0;
}
