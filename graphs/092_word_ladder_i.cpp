#include <bits/stdc++.h>
using namespace std;

/*
   solve: using bfs; go through the word
   replace every word if that's is in set you could replace and push that to
   queue, with steps increase and erase it from set

   if you hit endWord that's the ans (steps at that level)

   T.C = N * word.length * 26 * logN
*/
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    // steps and the word
    queue<pair<string, int>> q;
    // push the first word
    q.push({beginWord, 1});

    // keep track of words
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord);

    // simple bfs
    while (!q.empty()) {
      auto [word, step] = q.front();
      q.pop();

      // we traversed to endWord
      if (word == endWord)
        return step;

      // word - hat
      for (int i = 0; i < word.size(); i++) {
        char original = word[i];
        // traverse through alphabets
        for (char c = 'a'; c <= 'z'; c++) {
          // aat, bat
          word[i] = c;
          // it exist in set after replacing
          if (st.find(word) != st.end()) {
            q.push({word, step + 1});
            st.erase(word);
          }
        }
        // change to original after traversing for next
        // loop replacement
        word[i] = original;
      }
    }

    return 0;
  }
};
