#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    // track the number of repeated
    vector<int> frequency(26, 0);

    for (char &ch : tasks) {
      // indexing the characters
      frequency[ch - 'A']++;
    }

    // put it in maxHeap
    priority_queue<int> maxHeap;

    // add it to max heap
    for (int i = 0; i < 26; i++) {
      if (frequency[i] > 0) {
        maxHeap.push(frequency[i]);
      }
    }

    int time = 0;
    while (!maxHeap.empty()) {
      vector<int> tempFreq = {};
      for (int i = 0; i < n + 1; i++) {
        if (!maxHeap.empty()) {
          int freq = maxHeap.top();
          maxHeap.pop();
          freq--;
          tempFreq.push_back(freq);
        }
      }

      for (int el : tempFreq) {
        if (el > 0) {
          maxHeap.push(el);
        }
      }

      // if maxHeap becomes empty memans we have used all of the
      // elements and completed the thing so, we add the temp; only the ones we
      // used
      if (maxHeap.empty()) {
        time += tempFreq.size();
      } else {
        time += n + 1;
      }
    }

    return time;
  }
};
