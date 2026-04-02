#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumAmount(vector<vector<int>>& coins) {
    const int m = coins.size();
    const int n = coins[0].size();
    std::vector memo(
        m,
        std::vector(n, std::array<int, 3>{std::numeric_limits<int>::lowest(),
                                          std::numeric_limits<int>::lowest(),
                                          std::numeric_limits<int>::lowest()}));

    std::function<int(int, int, int)> dfs = [&](int i, int j, int k) -> int {
      if (i >= m || j >= n) {
        return std::numeric_limits<int>::lowest();
      }

      int x = coins[i][j];

      if (i == m - 1 && j == n - 1) {
        return k > 0 ? std::max(0, x) : x;
      }

      int res = memo[i][j][k];
      if (res != std::numeric_limits<int>::lowest()) {
        return res;
      }

      res = std::max(dfs(i + 1, j, k), dfs(i, j + 1, k)) + x;

      if (k > 0 && x < 0) {
        res = std::max({res, dfs(i + 1, j, k - 1), dfs(i, j + 1, k - 1)});
      }
      return memo[i][j][k] = res;
    };

    return dfs(0, 0, 2);
  }
};

int main() {
    std::vector<std::vector<int>> coins = {
        {0, -1, -1},
        {1, -2, 3},
        {2, -3, 4}
    };
    int res = Solution().maximumAmount(coins);
    std::cout << res << std::endl;
}