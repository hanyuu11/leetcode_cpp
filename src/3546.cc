#include <algorithm>
#include <ios>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>


using namespace std;

class Solution {
 public:
  bool canPartitionGrid(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    using ll = long long;
    std::vector<std::vector<ll>> sum(m + 1, std::vector<ll>(n + 1));
    ll total = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        sum[i + 1][j + 1] =
            sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
        total += grid[i][j];
      }
    }
    for (int i = 0; i < m - 1; ++i) {
      if (total == sum[i + 1][n] * 2) {
        return true;
      }
    }

    for (int j = 0; j < n - 1; ++j) {
      if (total == sum[m][j + 1] * 2) {
        return true;
      }
    }
    return false;
  }
};

int main() {
    std::vector<std::vector<int>> grid = {
        {1, 4},
        {2, 3}
    };
    Solution sl;
    bool res = sl.canPartitionGrid(grid);
    std::cout << std::boolalpha << res << std::endl;
    return 0;
}