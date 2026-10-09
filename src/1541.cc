#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>


using namespace std;

class Solution {
 public:
  int minInsertions(string s) {
    int insertions = 0, left_count = 0, index = 0;
    const int length = s.size();
    while (index < length) {
      char c = s[index];
      if (c == '(') {
        left_count++;
        index++;
      } else {
        if (left_count > 0) {
          left_count--;
        } else {
          insertions++;
        }

        if (index < length - 1 && s[index + 1] == ')') {
          index += 2;
        } else {
          insertions++;
          index++;
        }
      }
    }
    insertions += left_count * 2;
    return insertions;
  }
};

int main() {
    Solution sl;
    int res = sl.minInsertions("(()))");
    std::cout << res << "\n";
}