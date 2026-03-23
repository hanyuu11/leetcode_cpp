#include <algorithm>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProductPath(vector<vector<int>>& grid) {
    using ll = long long;
    const int mod = 1000000000 + 7;
    const size_t m = grid.size();
    const size_t n = grid[0].size();
    std::vector<std::vector<ll>> maxgt(m, std::vector<ll>(n));
    std::vector<std::vector<ll>> minlt(m, std::vector<ll>(n));
    maxgt[0][0] = grid[0][0];
    minlt[0][0] = grid[0][0];

    for (size_t i = 1; i < n; ++i) {
      maxgt[0][i] = minlt[0][i] = maxgt[0][i - 1] * grid[0][i];
    }
    for (size_t i = 1; i < m; ++i) {
      maxgt[i][0] = minlt[i][0] = maxgt[i - 1][0] * grid[i][0];
    }

    for (size_t i = 1; i < m; ++i) {
      for (size_t j = 1; j < n; ++j) {
        if (grid[i][j] >= 0) {
          maxgt[i][j] = std::max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
          minlt[i][j] = std::min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
        } else {
          maxgt[i][j] = std::min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
          minlt[i][j] = std::max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
        }
      }
    }

    if (maxgt[m - 1][n - 1] < 0) {
      return -1;
    }
    return maxgt[m - 1][n - 1] % mod;
  }
};

int main() {
    Solution sl;
    vector<vector<int>> grid = {
        {1, -2, 1},
        {1, -2, -3},
        {3, -4, 1}
    };
    auto res = sl.maxProductPath(grid);
    std::cout << res << "\n";
}