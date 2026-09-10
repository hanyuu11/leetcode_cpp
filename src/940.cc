#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>


using namespace std;

class Solution {
 public:
  int distinctSubseqII(string s) {
    constexpr int mod = 1000000007;
    std::vector<int> last(26, -1);

    const int n = s.size();

    std::vector<int> f(n, 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 26; ++j) {
        if (last[j] != -1) {
          f[i] = (f[i] + f[last[j]]) % mod;
        }
      }
      last[s[i] - 'a'] = i;
    }

    int ans = 0;
    for (int i = 0; i < 26; ++i) {
      if (last[i] != -1) {
        ans = (ans + f[last[i]]) % mod;
      }
    }

    return ans;
  }
};

int main() {
  std::string s = "abc";
  Solution sl;
  int ans = sl.distinctSubseqII(s);
  std::cout << ans << "\n";
}