#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class MinStack {
public:
  stack<int> st;

  // minimum value we have added so far
  // top will have the minimum value ? so far on that seq
  stack<int> minStack;

  MinStack() {}

  // [ 1, 2, 8 ] 4
  void push(int val) {
    st.push(val);
    // if the val is minimum
    int minVal = !minStack.empty() ? min(minStack.top(), val) : val;
    minStack.push(minVal);
  }

  void pop() {
    st.pop();
    minStack.pop();
  }

  int top() { return st.top(); }

  int getMin() { return minStack.top(); }
};
