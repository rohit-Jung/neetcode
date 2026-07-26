#include <bits/stdc++.h>
using namespace std;

/**
 * happy number- sum of squares eventually becomes one ?
 * meaning there is cycle if you connect em
 */
class Solution {
private:
  int findSquareSum(int num) {
    int sum = 0;

    while(num > 0) {
      int digit = num % 10;
      sum += digit * digit;

      num = num / 10;
    }

    return sum;
  }

public:
  bool isHappy(int n) {
    int slow = n;
    int fast = n;

    do {
      slow = findSquareSum(slow);
      fast = findSquareSum(findSquareSum(fast));

      if(slow == fast) { break; }
    } while(slow != fast);

    return slow == 1;  // happy number ends with 1
  }
};
