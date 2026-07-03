#include <functional>
#include <queue>
#include <vector>
using namespace std;

// solve; using a min head insert all when ever the size becomes more then
// k you just pop out
// mistake; you should pop inside the loop why ? ask yourself

// naive; store sorted only; insert by binary search; shift happens
class KthLargest {
public:
  priority_queue<int, vector<int>, greater<int>> minHeap;
  int s;
  KthLargest(int k, vector<int> &nums) {
    s = k;

    for (int &num : nums) {
      minHeap.push(num);
      if (minHeap.size() > s)
        minHeap.pop();
    }
  }

  int add(int val) {
    minHeap.push(val);

    if (minHeap.size() > s)
      minHeap.pop();

    return minHeap.top();
  }
};
