#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string encode(vector<string> &strs) {
    string str = "";

    for (auto el : strs) {
      int len = el.size();
      str += to_string(len) + "#" + el;
    }

    return str;
  }

  vector<string> decode(string s) {
    vector<string> solution;

    int i = 0;
    while (i < s.size()) {
      int j = i;

      while (s[j] != '#')
        j++;

      // up to j - i cause we need the length not the exact position
      int len = stoi(s.substr(i, j - i));

      string new_str = s.substr(j + 1, len);
      solution.emplace_back(new_str);

      i = 1 + j + len;
    }

    return solution;
  }
};
