#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

// solve; you have a maxHeap; start by taking last two elems; cause you need two
// greatest and strike them
// naive-similar; sort; take two greatest from last; take the diff and insert
// again
class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> maxHeap;
    for (int &stone : stones) {
      maxHeap.push(stone);
    }

    // you need at least two elems cause you are striking em
    while (maxHeap.size() > 1) {
      int a = maxHeap.top();
      maxHeap.pop();

      int b = maxHeap.top();
      maxHeap.pop();

      // now we have last two we push back
      maxHeap.push(abs(a - b));
    }

    // return the top element
    return maxHeap.top();
  }
};
