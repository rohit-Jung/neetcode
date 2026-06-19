#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    vector<char> stack;
    unordered_map<char, char> bracket_map = {
        {')', '('}, {'}', '{'}, {']', '['}};

    for (char str : s) {
      if (str == '(' || str == '{' || str == '[') {
        stack.emplace_back(str);
      } else {
        if (stack.empty())
          return false;

        char lst = stack.back();
        // check if current is valid closing
        bool isValidBrc = lst == bracket_map[str];
        if (!isValidBrc)
          return false;

        // remove the bracket
        stack.pop_back();
      }
    }

    // if empty it's valid
    return stack.empty();
  }
};
