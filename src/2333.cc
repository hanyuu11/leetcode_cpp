#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                             int k2) {
    const int n = nums1.size();
    std::vector<int> diff(n);
    for (size_t i = 0; i < n; ++i) {
      diff[i] = std::abs(nums1[i] - nums2[i]);
    }
    long long k = (long long)k1 + k2;
    if (std::accumulate(diff.begin(), diff.end(), 0LL) <= k) {
      return 0;
    }
    std::sort(diff.begin(), diff.end(), std::greater<>());
    diff.push_back(0);
    for (int i = 1; i <= n; ++i) {
      long long cost = (long long)(diff[i - 1] - diff[i]) * i;
      if (cost > k) {
        long long q = k / i, r = k % i;
        long long hi = diff[i - 1] - q;
        long long ans = hi * hi * (i - r) + (hi - 1) * (hi - 1) * r;
        for (int j = i; j < n; ++j) {
          ans += (long long)diff[j] * diff[j];
        }
        return ans;
      }
      k -= cost;
    }

    return 0;
  }
};

int main() {
  Solution sl;
  std::vector<int> nums1 = {1, 4, 10, 12};
  std::vector<int> nums2 = {5, 8, 6, 9};
  int k1 = 10;
  int k2 = 5;
  auto res = sl.minSumSquareDiff(nums1, nums2, k1, k2);
  std::cout << res << "\n";
}