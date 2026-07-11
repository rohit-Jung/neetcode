#include <bits/stdc++.h>
using namespace std;

/**
  solve:
  similar to course schedule,
  just return the order instead of the count here

  topologicalSort  question
   T.C: O(V + E)
   S.C: O(V + E)   // including adjacency list
   Extra auxiliary space (excluding graph): O(V)
 **/
class Solution {
private:
  // TODO: solve this using DFS too
  vector<int> topologicalSort(int numCourses,
                              unordered_map<int, vector<int>> &adjs,
                              vector<int> &indegree) {
    vector<int> ans;
    queue<int> que;

    // push into the queue the ones with indegree 0
    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0) {
        ans.push_back(i);
        que.push(i);
      }
    }

    // go through the queue
    while (!que.empty()) {
      int f = que.front();
      que.pop();

      // traverse through neighbours
      for (auto &v : adjs[f]) {
        indegree[v]--;

        if (indegree[v] == 0) {
          ans.push_back(v);
          que.push(v);
        }
      }
    }

    if (ans.size() == numCourses) {
      return ans;
    }

    return {};
  }

public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    unordered_map<int, vector<int>> adjs;
    vector<int> indegree(numCourses, 0);

    for (auto &v : prerequisites) {
      int a = v[0];
      int b = v[1];

      // b --> a;
      adjs[b].push_back(a);

      // indegree
      indegree[a]++;
    }

    return topologicalSort(numCourses, adjs, indegree);
  }
};
