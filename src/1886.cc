#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // C++ 这里的 = 拷贝是值拷贝，会得到一个新的数组
    auto matrix_new = matrix;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        matrix_new[j][n - i - 1] = matrix[i][j];
      }
    }
    return matrix_new;
  }

  bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    constexpr int num_max_rotations = 4;
    for (int i = 0; i < num_max_rotations; ++i) {
      mat = rotate(mat);
      if (mat == target) {
        return true;
      }
    }
    return false;
  }
};

int main(){
    Solution sl;
    vector<vector<int>> mat = {
        {0, 1}, {1, 0}
    };
    vector<vector<int>> target = {
        {1, 0}, {0, 1}
    };
    bool res = sl.findRotation(mat, target);
    std::cout << res << std::endl;
    return 0;
}