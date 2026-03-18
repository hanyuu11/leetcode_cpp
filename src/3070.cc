#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int countSubmatrices(vector<vector<int>>& grid, int k) {
    const size_t m = grid.size();
    const size_t n = grid[0].size();
    std::vector<int> cols(n);
    int res = 0;
    for (size_t i = 0; i < m; ++i) {
      int rows = 0;
      for (size_t j = 0; j < n; ++j) {
        cols[j] += grid[i][j];
        rows += cols[j];
        if (rows <= k) {
          ++res;
        }
      }
    }
    return res;
  }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> grid = {
        {7,6,3}, {6,6,1}
    };
    int res = s.countSubmatrices(grid, 18);
    std::cout << res << std::endl;
    return 0;
}