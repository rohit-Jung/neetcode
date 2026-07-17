#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  // topological sort BFS - Kahn's algorithm
  vector<int> topologicalSort(int V, vector<int> &indegree,
                              vector<vector<int>> &adjs,
                              vector<bool> &present) {
    // make the indegree
    queue<int> q;
    vector<int> topo;

    // push the indegree with 0 word dict
    for (int i = 0; i < 26; i++) {
      if (present[i] && indegree[i] == 0)
        q.push(i);
    }

    // go through the q
    while (!q.empty()) {
      int f = q.front();
      q.pop();
      topo.push_back(f);

      // through neighbors
      for (auto &v : adjs[f]) {
        indegree[v]--;

        if (indegree[v] == 0)
          q.push(v);
      }
    }

    if (topo.size() != V) {
      return {};
    }

    return topo;
  }

public:
  string foreignDictionary(vector<string> &words) {
    int n = words.size();
    vector<vector<int>> adjs(26);
    vector<int> indegree(26, 0);
    vector<bool> present(26, false);

    // mark characters as present
    for (string &word : words) {
      for (char &ch : word) {
        present[ch - 'a'] = true;
      }
    }

    // count vertices
    int V = 0;
    for (int i = 0; i < 26; i++) {
      if (present[i])
        V++;
    }

    // make the adacency graph
    for (int i = 0; i < n - 1; i++) {
      string s1 = words[i];
      string s2 = words[i + 1];

      int len = min(s1.size(), s2.size());

      // if  dictionary is invalid apple and then app
      if (s1.size() > s2.size() && s1.substr(0, s2.size()) == s2) {
        return "";
      }

      for (int j = 0; j < len; j++) {

        if (s1[j] != s2[j]) {
          int a = s1[j] - 'a';
          int b = s2[j] - 'a';

          // a --> b if the connection isn't present
          if (find(adjs[a].begin(), adjs[a].end(), b) == adjs[a].end()) {
            adjs[a].push_back(b);
            indegree[b]++;
          }

          break;
        }
      }
    }

    // get the topological sort
    vector<int> sorted = topologicalSort(V, indegree, adjs, present);
    if (sorted.empty())
      return "";

    // convert back to the letters
    string ans = "";
    for (int i = 0; i < sorted.size(); i++) {
      ans += char(sorted[i] + 'a');
    }
    return ans;
  }
};
