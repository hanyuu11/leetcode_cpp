#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfSets(int n, int k) {
    constexpr int MOD = 1000000007;
    std::vector<int> dp(n), prefix_sum(n + 1);
    for (int j = 0; j < n; ++j) {
      dp[j] = 1;
      prefix_sum[j + 1] = (prefix_sum[j] + dp[j]) % MOD;
    }
    for (int i = 1; i <= k; ++i) {
      dp[0] = 0;
      for (int j = 1; j < n; ++j) {
        dp[j] = (dp[j - 1] + prefix_sum[j]) % MOD;
      }
      for (int j = 0; j < n; ++j) {
        prefix_sum[j + 1] = (prefix_sum[j] + dp[j]) % MOD;
      }
    }
    return dp[n - 1];
  }
};

int main() {
    Solution sl;
    int res = sl.numberOfSets(30, 7);
    std::cout << res << "\n";
}