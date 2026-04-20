#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxDistance(vector<int>& colors) {
    int res = 0;
    for (int i = 0; i < colors.size(); ++i) {
      for (int j = colors.size() - 1; j > i; --j) {
        if (colors[i] != colors[j]) {
          res = std::max(res, j - i);
        }
      }
    }
    return res;
  }
};

int main() {
    Solution sl;
    std::vector<int> colors = {1, 1, 1, 6, 1 ,1 ,1};
    int res = sl.maxDistance(colors);
    std::cout << res << std::endl;
}