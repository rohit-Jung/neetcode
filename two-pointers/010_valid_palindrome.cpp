#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class Solution {
public:
  bool isPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;

    while (i < j) {
      // you can use isalnum too
      while (i < j && !isAlphaNum(s[i]))
        i++;

      while (i < j && !isAlphaNum(s[j]))
        j--;

      if (tolower(s[i]) != tolower(s[j]))
        return false;

      i++;
      j--;
    }

    return true;
  }

  bool isAlphaNum(char c) {
    return ('0' <= c && c <= '9') || ('a' <= c && c <= 'z') ||
           ('A' <= c && c <= 'Z');
  }
};
