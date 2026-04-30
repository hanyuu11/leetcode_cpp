#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxPathScore(vector<vector<int>>& grid, int k) {
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    std::vector<std::vector<std::vector<int>>> dp(
        m, std::vector<std::vector<int>>(
               n, std::vector<int>(
                      k + 1, std::numeric_limits<int>::min())));  // i, j, cost
    dp[0][0][0] = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int c = 0; c <= k; ++c) {
          if (dp[i][j][c] == std::numeric_limits<int>::min()) {
            continue;
          }
          if (i + 1 < m) {
            const int val = grid[i + 1][j];
            const int cost = (val == 0 ? 0 : 1);
            if (c + cost <= k) {
              dp[i + 1][j][c + cost] =
                  std::max(dp[i + 1][j][c + cost], dp[i][j][c] + val);
            }
          }
          if (j + 1 < n) {
            const int val = grid[i][j + 1];
            const int cost = (val == 0 ? 0 : 1);
            if (c + cost <= k) {
              dp[i][j + 1][c + cost] =
                  std::max(dp[i][j + 1][c + cost], dp[i][j][c] + val);
            }
          }
        }
      }
    }
    int ans = std::numeric_limits<int>::min();
    for (int c = 0; c <= k; ++c) {
      ans = std::max(ans, dp[m - 1][n - 1][c]);
    }
    return ans < 0 ? -1 : ans;
  }
};

int main() {
    Solution sl;
    std::vector<std::vector<int>> grid = {
        {0, 1},
        {2, 0}
    };
    int k = 2;
    int res = sl.maxPathScore(grid, k);
    std::cout << res << std::endl;
}