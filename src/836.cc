#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    // If a rec if empty.
    if (rec1[0] == rec1[2] || rec1[1] == rec1[3] || rec2[0] == rec2[2] ||
        rec2[1] == rec2[3]) {
      return false;
    }

    return !(
        rec1[2] <= rec2[0] ||
        rec1[0] >= rec2[2] ||
        rec1[1] >= rec2[3] ||
        rec1[3] <= rec2[1]
    );
  }
};

int main() {
    Solution sl;
    std::vector<int> vec1 = {0, 0, 2, 2};
    std::vector<int> vec2 = {1, 1, 3, 3};
    bool res = sl.isRectangleOverlap(vec1, vec2);
    std::cout << std::boolalpha << res << "\n";
}