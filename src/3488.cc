#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    std::unordered_map<int, std::vector<int>> m;
    const int n = nums.size();
    for (int i = 0; i < n; ++i) {
      m[nums[i]].push_back(i);
    }

    for (auto& [_, indices] : m) {
      int x = indices[0];
      indices.insert(indices.begin(), indices.back() - n);
      indices.push_back(x + n);
    }

    const size_t s = queries.size();
    for (size_t i = 0; i < s; ++i) {
      const int query = queries[i];
      const int num = nums[query];
      const auto& indices = m[num];
      if (indices.size() == 3) {
        queries[i] = -1;
        continue;
      }
      int pos = std::lower_bound(indices.begin(), indices.end(), query) -
                indices.begin();
      queries[i] = std::min(indices[pos + 1] - indices[pos],
                            indices[pos] - indices[pos - 1]);
    }
    return queries;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution sl;
  std::vector<int> nums = {1, 3, 1, 4, 1, 3, 2};
  std::vector<int> queries = {0, 3, 5};
  const auto res = sl.solveQueries(nums, queries);
  for (const int n : res) {
    std::cout << n << ", " << std::endl;
  }
  return 0;
}
