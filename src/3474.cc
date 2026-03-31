#include <algorithm>
#include <iostream>
#include <numeric>
#include <optional>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string generateString(string str1, string str2) {
    const size_t n = str1.size();
    const size_t m = str2.size();
    std::string s(n + m - 1, 'a');
    std::vector<int> fixed(n + m - 1, 0);
    for (size_t i = 0; i < n; ++i) {
      if (str1[i] == 'T') {
        for (size_t j = i; j < i + m; ++j) {
          if (fixed[j] && s[j] != str2[j - i]) {
            return "";
          }
          s[j] = str2[j - i];
          fixed[j] = 1;
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      if (str1[i] == 'F') {
        bool flag = false;
        int idx = -1;
        for (int j = i + m - 1; j >= i; --j) {
          if (str2[j - i] != s[j]) {
            flag = true;
          }
          if (idx == -1 && !fixed[j]) {
            idx = j;
          }
        }
        if (flag) {
          continue;
        }
        if (idx != -1) {
          s[idx] = 'b';
        } else {
          return "";
        }
      }
    }
    return s;
  }
};

int main() {
  Solution sl;
  const std::string res = sl.generateString("F", "d");
  std::cout << res << std::endl;
  return 0;
}