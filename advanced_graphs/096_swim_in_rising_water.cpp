#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
   approach 1: dijsktra's (minimum path maximum value)
   T.C - V = n^2, pq - log(V) and exploring V so Vlog(V) = O(n^2(log n^2))
   S.C - Dist + PQ - V = O(n^2)
   dijsktra is usually faster as it explores nodes only once 

   approach 2: binary search (maximize in minimum)
   T.C - binary search O(n^2) and DFS n^2 so O(n^2(log n^2))
   S.C - visited array and recursion stack  - O(n^2)
 */
class Solution {
public:
  // using dijsktra
  typedef pair<int, pair<int, int>> P; // { time, { r, c}}
  static constexpr int dr[4] = {1, -1, 0, 0};
  static constexpr int dc[4] = {0, 0, 1, -1};

  int swimInWaterDjisktra(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    // minheap result
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<vector<int>> result(m, vector<int>(n, INT_MAX));

    pq.push({grid[0][0], {0, 0}});
    result[0][0] = grid[0][0];

    auto isSafe = [&](const int &i, const int &j) {
      if (i < 0 || j < 0 || i >= m || j >= n) {
        return false;
      }

      return true;
    };

    while (!pq.empty()) {
      int currTime = pq.top().first;
      auto [r, c] = pq.top().second;
      pq.pop();

      // reached the end
      if (r == m - 1 && c == n - 1) {
        return currTime;
      }

      // skip the worse answer
      if (currTime > result[r][c])
        continue;

      // traverse direction
      for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (isSafe(nr, nc)) {
          // get max time till now for the grid, cause it's gonna be the answer
          int maxTimeTillNow = max(currTime, grid[nr][nc]);

          // is the max time till now better ?
          if (maxTimeTillNow < result[nr][nc]) {
            pq.push({maxTimeTillNow, {nr, nc}}); // push since it's better
            result[nr][nc] = maxTimeTillNow;     // update
          }
        }
      }
    }

    return -1;
  }

  bool possibleToReach(int r, int c, vector<vector<int>> &grid, int mid,
                       vector<vector<bool>> &visited) {
    // out of bounds
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) {
      return false;
    }

    // current has greater time  cannot go
    if (grid[r][c] > mid) {
      return false;
    }

    // visited
    if (visited[r][c])
      return false;

    // its the end end base ?
    if (r == grid.size() - 1 && c == grid[0].size() - 1) {
      return true;
    }

    visited[r][c] = true;

    // traverse in four directions
    for (int i = 0; i < 4; i++) {
      int nr = i + dr[i];
      int nc = c + dc[i];

      if (possibleToReach(nr, nc, grid, mid, visited)) {
        return true;
      }
    }

    return false;
  }

  int swimInWater(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    // binary search
    int l = 0;
    int r = m * n - 1; // m^2 - 1 last element

    int result = 0;

    while (l <= r) {
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      int mid = l + (r - l) / 2;

      if (possibleToReach(0, 0, grid, mid, visited)) {
        result = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return result;
  }
};
