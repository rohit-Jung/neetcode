#include <bits/stdc++.h>
using namespace std;

// solve ; maintain maxHeap that sorts accordign to distance, maxDistance at top
// insert distance and corresponding point and return the top ones for k
// similar to k largest you can only keep the kth elems
// naive;
class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    priority_queue<pair<int, vector<int>>> maxHeap;

    for (vector<int> &point : points) {
      int dist = point[0] * point[0] + point[1] * point[1];
      maxHeap.push({dist, {point[0], point[1]}});
      if (maxHeap.size() > k)
        maxHeap.pop();
    }

    vector<vector<int>> sol;
    // this check can be changed
    while (k--) {
      sol.push_back(maxHeap.top().second);
      maxHeap.pop();
    }

    return sol;
  }
};
