#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int furthestDistanceFromOrigin(string moves) {
    int l_count = 0;
    int r_count = 0;
    int u_count = 0;
    for (const auto& c : moves) {
      if (c == 'L') {
        ++l_count;
      } else if (c == 'R') {
        ++r_count;
      } else {
        ++u_count;
      }
    }
    if (l_count > r_count) {
      return l_count + u_count - r_count;
    }
    return r_count + u_count - l_count;
  }
};

int main() {
    std::string moves = "L_RL__R";
    Solution sl;
    int res = sl.furthestDistanceFromOrigin(moves);
    std::cout << res << std::endl;
}