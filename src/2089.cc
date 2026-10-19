#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        auto it = std::find(nums.begin() ,nums.end(), target);
        if(it == nums.end()){
            return {};
        }
        int index = it - nums.begin();
        std::vector<int> indices;
        while(index < nums.size() && nums[index] == target){
            indices.push_back(index);
            ++index;
        }
        return indices;
    }
};

int main(){
    Solution sl;
    std::vector<int> nums = {1, 2, 5, 2, 3};
    int target = 2;
    auto ans = sl.targetIndices(nums, target);
    for(const int a: ans){
        std::cout << a << ", ";
    }
    std::cout << "\n";
}