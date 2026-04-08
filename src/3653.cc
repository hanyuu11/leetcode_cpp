#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>


using namespace std;

class Solution {
 public:
  int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    static const int MOD = 1e9 + 7;
    for (const auto& query : queries) {
      int l = query[0];
      int r = query[1];
      int k = query[2];
      int v = query[3];
      for (int idx = l; idx <= r; idx += k) {
        nums[idx] = ((long long)nums[idx] * v) % MOD;
      }
    }
    int res = 0;
    for (const int num : nums) {
      res ^= num;
    }
    return res;
  }
};

int main() {
    Solution sl;
    vector<int> nums = {1, 1, 1};
    vector<vector<int>> queries = {
        {0, 2, 1, 4}
    };
    int res = sl.xorAfterQueries(nums, queries);
    std::cout << res << std::endl;
}