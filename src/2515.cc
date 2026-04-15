#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  std::string PrevString(const std::vector<std::string>& words, int& idx) {
    const int n = static_cast<int>(words.size());
    idx = (idx - 1 + n) % n;
    return words[idx];
  }

  std::string NextString(const std::vector<std::string>& words, int& idx) {
    const int n = static_cast<int>(words.size());
    idx = (idx + 1) % n;
    return words[idx];
  }

  int closestTarget(vector<string>& words, string target, int startIndex) {
    if (words[startIndex] == target) {
      return 0;
    }
    int l = startIndex, r = startIndex;
    for (int i = 1; i < static_cast<int>(words.size()); ++i) {
      const auto prev = PrevString(words, l);
      const auto next = NextString(words, r);
      if (prev == target || next == target) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  std::vector<std::string> words = {"a", "b", "leetcode"};
  std::string target = "leetcode";
  Solution sl;
  int res = sl.closestTarget(words, target, 0);
  std::cout << res << std::endl;
}