#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool checkStrings(string s1, string s2) {
    constexpr int kNumCharacters = 26;
    std::array<int, kNumCharacters> s1_odd;
    std::array<int, kNumCharacters> s1_even;
    std::array<int, kNumCharacters> s2_odd;
    std::array<int, kNumCharacters> s2_even;
    for (size_t i = 0; i < s1.size(); ++i) {
      if (i % 2 == 0) {
        s1_even[s1[i] - 'a'] += 1;
        s2_even[s2[i] - 'a'] += 1;
      } else {
        s1_odd[s1[i] - 'a'] += 1;
        s2_odd[s2[i] - 'a'] += 1;
      }
    }
    return s1_even == s2_even && s1_odd == s2_odd;
  }
};

int main() {
    Solution sl;
    bool res = sl.checkStrings("abcdba", "cabdab");
    std::cout << std::boolalpha << res << std::endl;
    return 0;
}