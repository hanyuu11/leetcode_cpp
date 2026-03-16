#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getBiggestThree(vector<vector<int>>& grid) {
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    std::set<int> areas;
    const auto calc_area = [&grid](int i, int j, int r) {
      if (r == 0) {
        return grid[i][j];
      }
      int res = 0;

      for (int k = 0; k < r; ++k) {
        res += grid[i + k][j + r - k];
        res += grid[i + r - k][j - k];
        res += grid[i - r + k][j + k];
        res += grid[i - k][j - r + k];
      }
      return res;
    };
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int r = 0;; ++r) {
          if (i - r < 0 || i + r >= m || j - r < 0 || j + r >= n)
            break;

          int area = calc_area(i, j, r);
          areas.insert(area);
          if (areas.size() > 3) {
            areas.erase(areas.begin());
          }
        }
      }
    }
    std::vector<int> ans(areas.begin(), areas.end());
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  Solution s;
  std::vector<std::vector<int>> grid = {{3, 4, 5, 1, 3},
                                        {3, 3, 4, 2, 3},
                                        {20, 30, 200, 40, 10},
                                        {1, 5, 5, 4, 1},
                                        {4, 3, 2, 2, 5}};

  auto ans = s.getBiggestThree(grid);
  for (const int a : ans) {
    std::cout << a << std::endl;
  }
  return 0;
}