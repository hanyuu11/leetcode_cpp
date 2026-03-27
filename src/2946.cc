#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool areSimilar(vector<vector<int>>& mat, int k) {
    const int m = static_cast<int>(mat.size());
    const int n = static_cast<int>(mat[0].size());
    k = k % n;
    for (int i = 0; i < m; ++i) {
      auto v = mat[i];
      if (k % 2 == 1) {
        std::rotate(v.begin(), v.end() - k, v.end());
      } else {
        std::rotate(v.begin(), v.begin() + k, v.end());
      }
      if(v != mat[i]){
        return false;
      }
    }
    return true;
  }
};

int main(){
    std::vector<std::vector<int>> mat = {
        {1,2,1,2},
        {5,5,5,5},
        {6,3,6,3}
    };
    bool res = Solution().areSimilar(mat, 2);
    std::cout << std::boolalpha << res << std::endl;
    return 0;
}