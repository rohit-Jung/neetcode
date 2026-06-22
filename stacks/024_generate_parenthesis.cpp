#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class Solution {
private:
  // ohh fxk this is dfs?
  // TODO: try dfs

  // you should pass by ref : we have pointers here mf
  int backtrack(int open, int closed, int n, vector<string> &sol,
                vector<char> &stack) {

    string str = "";
    // collect and put on the sol
    if (open == n && closed == n) {
      for (char c : stack) {
        str += c;
      }

      sol.push_back(str);
      return 0;
    }

    // if we can open we open;
    if (open < n) {
      stack.push_back('(');
      // open as much as you can ( you gonna regret later, trust me bro )
      backtrack(open + 1, closed, n, sol, stack);
      stack.pop_back();
    }

    if (open > closed) {
      stack.push_back(')');
      backtrack(open, closed + 1, n, sol, stack);
      stack.pop_back();
    }

    return 0;
  }

public:
  vector<string> generateParenthesis(int n) {
    vector<string> sol;
    vector<char> stack;

    int open = 0;
    int closed = 0;

    backtrack(open, closed, n, sol, stack);
    return sol;
  }
};
