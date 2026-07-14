#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
private:
  bool dfs(string from, vector<string> &path, int tickets,
           vector<string> &result,
           unordered_map<string, vector<string>> &adjs) {

    // push to stack
    path.push_back(from);

    // base case if path == number of tickets
    if (path.size() == tickets + 1) {
      result = path;
      return true;
    }

    // visit neigh
    vector<string> &neigh = adjs[from];
    for (int i = 0; i < neigh.size(); i++) {
      string to = neigh[i];

      // erase from  list to avoid cycle
      neigh.erase(neigh.begin() + i);

      if (dfs(to, path, tickets, result, adjs)) {
        return true;
      }

      // put to the list back for another
      neigh.insert(neigh.begin() + i, to);
    }

    path.pop_back();

    return false;
  }

public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    // construct / build the graph
    unordered_map<string, vector<string>> adjs;
    for (auto &ticket : tickets) {
      string a = ticket[0];
      string b = ticket[1];
      adjs[a].push_back(b);
    }

    // sort in lexical order
    for (auto &edges : adjs) {
      sort(begin(edges.second), end(edges.second));
    }

    // dfs
    vector<string> path;
    vector<string> result;
    dfs("JFK", path, tickets.size(), result, adjs);
    return result;
  }
};
