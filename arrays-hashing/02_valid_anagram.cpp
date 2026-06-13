#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // naive is sort it and check the equality maybe
  // other approach is vec of 26 chars and increase one decrease other if
  // anything is not zero they aren't anagrams
  // O(n) solution
  bool isAnagram(string s, string t) {
    // if the size isn't equal it's not an anagram
    if (s.size() != t.size())
      return false;

    map<char, int> first;
    map<char, int> second;

    // count the characters in each word
    // O(n)
    for (auto el : s) {
      if (first.find(el) != first.end())
        first[el] += 1;
      else
        first[el] = 1;
    }

    // O(n)
    for (auto el : t) {
      if (second.find(el) != second.end())
        second[el] += 1;
      else
        second[el] = 1;
    }

    // O(n)
    for (auto el : s) {
      if (first[el] != second[el])
        return false;
    }

    return true;
  }
};
