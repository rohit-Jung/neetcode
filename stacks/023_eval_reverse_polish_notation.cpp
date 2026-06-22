#include <bits/stdc++.h>
#include <cctype>
#include <string>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class Solution {
private:
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

public:
  // store in a stack and operate when sign encountered
  int evalRPN(vector<string> &tokens) {
    stack<int> store;

    for (string c : tokens) {
      if (c.size() > 1 || isdigit(c[0])) {
        store.push(stoi(c));
      } else {
        if (store.size() < 2) {
          return 0;
        }

        int last = store.top();
        store.pop();
        int secondLast = store.top();
        store.pop();

        int ans = evaluateOperation(secondLast, last, c[0]);
        store.push(ans);
      }
    }
    return store.top();
  }
};

int main() {
  vector<string> tokens = {"4", "13", "5", "/", "+"};
  Solution sol;
  cout << sol.evalRPN(tokens);
}
