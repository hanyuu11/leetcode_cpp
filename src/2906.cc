#include <algorithm>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>


using namespace std;

class Solution {
 public:
  vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    constexpr int mod = 12345;
    const int n = static_cast<int>(grid.size());
    const int m = static_cast<int>(grid[0].size());
    vector<vector<int>> p(n, vector<int>(m));

    using ll = long long;
    ll suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = m - 1; j >= 0; --j) {
        p[i][j] = suffix;
        suffix = suffix * grid[i][j] % mod;
      }
    }

    ll prefix = 1;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            p[i][j] = p[i][j] * prefix % mod;
            prefix = prefix * grid[i][j] % mod;
        }
    }

    return p;
  }
};

int main() {
    Solution sl;
    vector<vector<int>> grid = {
        {1, 2},
        {3, 4}
    };
    auto vec = sl.constructProductMatrix(grid);
    for(const auto& v: vec){
        for(const int i: v){
            std::cout << i << ", ";
        }
        std::cout << "\n";
    }
    return 0;
}