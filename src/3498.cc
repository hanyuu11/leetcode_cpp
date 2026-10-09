#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int reverseDegree(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      int pos = 26 - (c - 'a');
      ans += pos * (i + 1);
    }
    return ans;
  }
};

int main() {
  Solution sl;
  int ans = sl.reverseDegree("zaza");
  std::cout << ans << "\n";
}