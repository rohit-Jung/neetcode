#include <bits/stdc++.h>
#include <stack>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class MinStack {
public:
  MinStack() {
    stack<int> s;
    stack<int> m;
  }

  // idk oop in cpp
  void push(int val) { s.push(val); }

  void pop() {}

  int top() {}

  int getMin() {}
};
