#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
private:
  vector<string> ans;
  unordered_map<char, string> letterMap = {
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

  void backtrack(string &digits, int idx, string &curr) {
    if (curr.size() == digits.size()) {
      ans.push_back(curr);
      return;
    }

    string chars = letterMap[digits[idx]];

    // check every letters so i = 0;
    for (int i = 0; i < chars.size(); i++) {
      curr.push_back(chars[i]);

      // move to next idx
      backtrack(digits, idx + 1, curr);
      curr.pop_back();
    }
  }

public:
  vector<string> letterCombinations(string digits) {
    // base case when no digits
    if (digits == "")
      return ans;

    string curr;
    backtrack(digits, 0, curr);
    return ans;
  }
};

int main() {
  string digits = "34";

  Solution sol{};
  vector<string> ans = sol.letterCombinations(digits);
  for (string an : ans) {
    cout << an << endl;
  }
}
