#include <bits/stdc++.h>
using namespace std;

class CountSquares {
public:
  // x -> y, count
  unordered_map<int, unordered_map<int, int>> cnt;
  CountSquares() {
    cnt = unordered_map<int, unordered_map<int, int>>();
  }

  void add(vector<int> point) {
    int x = point[0], y = point[1];
    cnt[x][y]++;
  }

  // calculate left and right side
  int count(vector<int> point) {
    int x = point[0], y = point[1];
    int count = 0;

    for(auto& [ny, freq] : cnt[x]) {
      if(ny == y) continue;  // both are same points
      int side = abs(ny - y);

      count += freq * cnt[x + side][y] * cnt[x + side][ny];  // right side sq.
      count += freq * cnt[x - side][y] * cnt[x - side][ny];  // left side
    }

    return count;
  }
};
