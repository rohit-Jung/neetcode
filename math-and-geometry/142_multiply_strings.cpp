#include "../debugging.h"
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

// multiply and return as string
// becareful on position of carry and position of digit
// add the digit to product not the carry
class Solution {
public:
  string multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0") return "0";

    // T.C- O(l1 * l2) S.C- O(l1 + l2)
    int l1 = num1.size();
    int l2 = num2.size();
    vector<int> result(l1 + l2, 0);  // max length is l1 + l2

    // index from last
    for(int i = l1 - 1; i >= 0; i--) {
      // since there are two layers
      for(int j = l2 - 1; j >= 0; j--) {
        int d1 = num1[i] - '0';
        int d2 = num2[j] - '0';  // subtract '0' to get the int

        int product = d1 * d2;

        // calculate the positions for the product
        int p1 = i + j + 1;  // put the carry one step before
        int p2 = i + j;      // current digit

        int sum = product + result[p1];  // add to current digit

        result[p1] = sum % 10;   // the digit on p1
        result[p2] += sum / 10;  // the carry on p2
      }
    }

    string ans = "";
    for(int digit : result) {
      if(ans.empty() && digit == 0) continue;
      ans += digit + '0';
    }

    return ans.empty() ? "0" : ans;
  }
};
