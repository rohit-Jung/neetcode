#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class Solution {
public:
  int evaluateOperation(int a, int b, char operation) {
    switch (operation) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
    default:
      return 0;
    }
  }

  int evalPolishNotation(string s) {
    vector<int> store;

    for (auto c : s) {
      if (c != '+' && c != '-' && c != '*' && c != '/') {
        store.push_back(c - '0');
      } else {
        if (store.size() < 2) {
          return 0;
        }

        int last = store[store.size() - 1];
        int secondLast = store[store.size() - 2];
        int ans = evaluateOperation(secondLast, last, c);

        store.pop_back();
        store.pop_back();
        store.push_back(ans);
      }
    }
    return store[0];
  }
};
