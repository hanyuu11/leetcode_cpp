#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  const int mod = 1e9 + 7;
  using ll = long long;

  int pow(ll x, ll y) {
    ll res = 1;
    for (; y; y >>= 1) {
      if (y & 1) {
        res = res * x % mod;
      }
      x = x * x % mod;
    }
    return res;
  }

  int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    const int n = static_cast<int>(nums.size());
    const int T = static_cast<int>(sqrt(n));
    std::vector<std::vector<std::vector<int>>> groups(T);  // k -> {(l, r, v)}
    for (const auto& q : queries) {
      int l = q[0], r = q[1], k = q[2], v = q[3];
      if (k < T) {
        groups[k].push_back({l, r, v});
      } else {
        for (int i = l; i <= r; i += k) {
          nums[i] = (ll)nums[i] * v % mod;
        }
      }
    }

    std::vector<ll> dif(n + T);
    // Enumerate over steps
    for (int k = 1; k < T; ++k) {
      if (groups[k].empty()) {
        continue;
      }
      std::fill(dif.begin(), dif.end(), 1);
      for (const auto& q : groups[k]) {
        int l = q[0], r = q[1], v = q[2];
        dif[l] = dif[l] * v % mod;
        int R = ((r - l) / k + 1) * k + l;
        dif[R] = dif[R] * pow(v, mod - 2) % mod;
      }

      for (int i = k; i < n; i++) {
        dif[i] = dif[i] * dif[i - k] % mod;
      }
      for (int i = 0; i < n; i++) {
        nums[i] = 1ll * nums[i] * dif[i] % mod;
      }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
      res = res ^ nums[i];
    }
    return res;
  }
};

int main() {
  Solution sl;
  std::vector<int> nums = {2, 3, 1, 5, 4};
  std::vector<std::vector<int>> queries = {{1, 4, 2, 3}, {0, 2, 1, 2}};
  int res = sl.xorAfterQueries(nums, queries);
  std::cout << res << std::endl;
}