#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int getMinDistance(vector<int>& nums, int target, int start) {
    int l = start, r = start;
    while (l >= 0 || r < nums.size()) {
      if (l >= 0 && nums[l] == target) {
        return std::abs(l - start);
      }
      if (r < nums.size() && nums[r] == target) {
        return std::abs(r - start);
      }
      --l;
      ++r;
    }
    return -1;
  }
};

int main(){
    Solution sl;
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int res = sl.getMinDistance(nums, 5, 3);
    std::cout << res << std::endl;
}