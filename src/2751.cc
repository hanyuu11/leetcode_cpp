#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  struct Robot {
    int pos;
    int health;
    char dir;
    int idx;  // 原始下标
  };

  vector<int> survivedRobotsHealths(vector<int>& positions,
                                    vector<int>& healths,
                                    string directions) {
    int n = positions.size();
    vector<Robot> robots;
    robots.reserve(n);

    for (int i = 0; i < n; ++i) {
      robots.push_back({positions[i], healths[i], directions[i], i});
    }

    // 按位置排序
    sort(robots.begin(), robots.end(),
         [](const Robot& a, const Robot& b) {
           return a.pos < b.pos;
         });

    // 栈里存的是排序后数组中的下标，且这些机器人方向都是 R
    vector<int> st;

    for (int i = 0; i < n; ++i) {
      if (robots[i].dir == 'R') {
        st.push_back(i);
      } else {  // 当前是 L
        while (!st.empty() && robots[i].health > 0) {
          int j = st.back();  // 最近的一个向右机器人

          if (robots[j].health < robots[i].health) {
            // 栈顶 R 死亡，当前 L 扣 1 点血，继续碰撞
            robots[i].health -= 1;
            robots[j].health = 0;
            st.pop_back();
          } else if (robots[j].health > robots[i].health) {
            // 当前 L 死亡，栈顶 R 扣 1 点血
            robots[j].health -= 1;
            robots[i].health = 0;
            break;
          } else {
            // 同归于尽
            robots[j].health = 0;
            robots[i].health = 0;
            st.pop_back();
            break;
          }
        }
      }
    }

    // 按原始顺序收集幸存者
    vector<pair<int, int>> survived;  // {原始下标, health}
    for (const auto& robot : robots) {
      if (robot.health > 0) {
        survived.push_back({robot.idx, robot.health});
      }
    }

    sort(survived.begin(), survived.end());

    vector<int> ans;
    ans.reserve(survived.size());
    for (const auto& [idx, h] : survived) {
      ans.push_back(h);
    }

    return ans;
  }
};

int main() {
  Solution sl;
}