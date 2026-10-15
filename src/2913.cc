#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>


using namespace std;

class Solution {
 public:
  int sumCounts(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j <= nums.size(); ++j) {
        std::unordered_map<int, int> m;
        for (int k = i; k < j; ++k) {
          m[nums[k]]++;
        }  
        ans += m.size() * m.size();
      }
    }
    return ans;
  }
};

int main() {
  Solution sl;
  std::vector<int> nums = {1, 2, 1};
  int res = sl.sumCounts(nums);
  std::cout << res << "\n";
}