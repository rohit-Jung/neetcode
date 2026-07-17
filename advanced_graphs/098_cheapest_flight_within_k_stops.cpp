#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

/*
   directed graph with cheapest(minimum) : intution probably dijkstra

   dijsktra doesn't work with negative edges ?  { 0, -1 } - { -2, -1 }
   won't detect negative cycle: weight sum < 0

   bellman ford's algorithm: works
*/
using P = pair<int, int>;       // time, node?
using T = tuple<int, int, int>; // time, node, stops ?

class Solution {
  int dijkstra(int V, int src, vector<vector<P>> &adjs, int k, int dst) {
    vector<vector<int>> result(V, vector<int>(k + 2, INT_MAX));
    int stops = 0;

    priority_queue<T, vector<T>, greater<T>> pq; // min heap
    pq.push({0, src, stops});
    result[src][stops] = 0;

    int j = 0;
    while (!pq.empty()) {
      auto [price, node, stops] = pq.top();
      pq.pop();

      if (node == dst)
        return price;

      // skip the greater one
      if (stops > k)
        continue;

      // traverse through connected
      for (auto &[adjPrice, adjNode] : adjs[node]) {
        int newPrice = adjPrice + price;

        if (newPrice < result[adjNode][stops + 1]) {
          result[adjNode][stops + 1] = newPrice;
          pq.push({result[adjNode][stops + 1], adjNode, stops + 1});
        }
      }
    }
    return -1;
  }

public:
  int findCheapestPriceDijsktra(int n, vector<vector<int>> &flights, int src,
                                int dst, int k) {
    if (src == dst || n <= 1) {
      return src;
    }

    // make a directed graph first
    vector<vector<P>> adjs(n); // n is the number of vertices
    for (vector<int> &flight : flights) {
      int a = flight[0];
      int b = flight[1];
      int p = flight[2];

      adjs[a].push_back({p, b});
    }

    return dijkstra(n, src, adjs, k, dst);
  }

  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // at most k+1 edges [ 0, 1, 2 ]
    for (int i = 0; i < k + 1; i++) { // i = 2 means using 2 edge (flight)

      vector<int> temp = dist; // without temp

      for (vector<int> &edge : flights) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
          temp[v] = dist[u] + w;
        }
      }

      dist = temp;
    }

    return dist[dst] == INT_MAX ? -1 : dist[dst];
  }
};

int main() {
  int n = 4;
  vector<vector<int>> flights = {{0, 1, 1}, {0, 2, 5}, {1, 2, 1}, {2, 3, 1}};
  int src = 0;
  int dst = 3;
  int k = 1;

  Solution sol{};
  cout << sol.findCheapestPrice(n, flights, src, dst, k);
}
