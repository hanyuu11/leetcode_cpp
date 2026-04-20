#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    const int n1 = nums1.size();
    const int n2 = nums2.size();
    int i = 0;
    int res = 0;
    for (int j = 0; j < n2; ++j) {
      while (i < n1 && nums1[i] > nums2[j]) {
        ++i;
      }
      if (i < n1) {
        res = std::max(res, j - i);
      }
    }
    return res;
  }
};

int main() {
    Solution sl;
    std::vector<int> nums1 = {55, 30, 5, 4, 2};
    std::vector<int> nums2 = {100, 20, 10, 10, 5};
    int res = sl.maxDistance(nums1, nums2);
    std::cout << res << std::endl;
}