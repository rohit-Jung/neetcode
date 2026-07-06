#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<string> sol;

  // check if it's valid seq
  bool isValidBraceSeq(string &str) {
    int count = 0;

    for (char c : str) {
      if (c == '(')
        count++;
      else
        count--;

      // ())(  1 -1 -1 // should never go in negative
      if (count < 0)
        return false;
    }

    return count == 0;
  }

  // base condition if the length is double
  // if it's valid Seq then
  void solve(string &curr, int n) {
    // why 2 * n as it should be pair
    if (curr.size() == 2 * n) {
      if (isValidBraceSeq(curr)) {
        sol.push_back(curr);
        return;
      }
    }

    // for (
    curr.push_back('(');
    solve(curr, n);
    curr.pop_back();

    // for )
    curr.push_back(')');
    solve(curr, n);
    curr.pop_back();
  }

public:
  // approach 1: explore every possiblity with ( and )
  vector<string> generateParenthesis(int n) {
    string curr = "";
    solve(curr, n);
    return sol;
  }
};
