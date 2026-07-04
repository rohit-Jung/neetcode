#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
  priority_queue<int> leftMaxHeap;
  priority_queue<int, vector<int>, greater<int>> rightMinHeap;

public:
  MedianFinder() {
    leftMaxHeap = priority_queue<int>();
    rightMinHeap = priority_queue<int, vector<int>, greater<int>>();
  }

  void addNum(int num) {
    // first should be on left for now
    if (leftMaxHeap.empty() || num < leftMaxHeap.top()) {
      leftMaxHeap.push(num);
    } else {
      rightMinHeap.push(num);
    }

    // maintain the odd on left;
    int sizeDiff = abs((int)leftMaxHeap.size() - (int)rightMinHeap.size());
    if (sizeDiff > 1) {
      rightMinHeap.push(leftMaxHeap.top());
      leftMaxHeap.pop();
    } else if (rightMinHeap.size() > leftMaxHeap.size()) {
      leftMaxHeap.push(rightMinHeap.top());
      rightMinHeap.pop();
    }
  }

  double findMedian() {
    if (leftMaxHeap.size() == rightMinHeap.size()) {
      return ((double)(leftMaxHeap.top() + rightMinHeap.top()) / 2);
    }

    return leftMaxHeap.top();
  }
};
