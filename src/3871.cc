#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        long long p = 1000, res = 0;
        while (p <= n) {
            res += n - p + 1;
            p *= 1000;
        }
        return res;
    }
};

int main() {
    Solution sl;
    int res = sl.countCommas(1002);
    std::cout << res << "\n";
}