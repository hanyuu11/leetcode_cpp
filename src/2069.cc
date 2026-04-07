#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Robot {
 public:
  Robot(int width, int height) {
    for (int i = 0; i < width; ++i) {
      pos.emplace_back(i, 0);
      dir.emplace_back(0);
    }
    for (int i = 1; i < height; ++i) {
      pos.emplace_back(width - 1, i);
      dir.emplace_back(1);
    }
    for (int i = width - 2; i >= 0; --i) {
      pos.emplace_back(i, height - 1);
      dir.emplace_back(2);
    }
    for (int i = height - 2; i > 0; --i) {
      pos.emplace_back(0, i);
      dir.emplace_back(3);
    }
    dir[0] = 3;
  }

  void step(int num) {
    moved = true;
    idx = (idx + num) % pos.size();
  }

  vector<int> getPos() { return {pos[idx].first, pos[idx].second}; }

  string getDir() {
    if (!moved) {
      return "East";
    }
    return to_dir[dir[idx]];
  }

 private:
  bool moved = false;
  int idx = 0;
  vector<pair<int, int>> pos;
  vector<int> dir;
  unordered_map<int, string> to_dir = {{0, "East"},
                                       {1, "North"},
                                       {2, "West"},
                                       {3, "South"}};
};

int main() {
  Robot* obj = new Robot(6, 3);
  obj->step(2);
  obj->step(2);
  std::cout << obj->getPos()[0] << "," << obj->getPos()[1] << std::endl;
  std::cout << obj->getDir() << std::endl;
  obj->step(2);
  obj->step(1);
  obj->step(4);
  std::cout << obj->getPos()[0] << "," << obj->getPos()[1] << std::endl;
  std::cout << obj->getDir() << std::endl;
  return 0;
}