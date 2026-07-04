#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  // partition algorithm for Hoares' partition @returns pivot index
  // hoare: just a valid partiton boundry
  // [left side]  [right side]
  // ≤ pivot      ≥ pivot
  int hoare_partition(vector<int> &nums, int low, int high) {
    int pivot = nums[low];

    int i = low - 1;
    int j = high + 1;

    while (true) {
      do {
        i++;
      } while (nums[i] > pivot); // larger on left

      do {
        j--;
      } while (nums[j] < pivot); // smaller on right

      if (i >= j)
        return j;

      swap(nums[i], nums[j]);
    }
  }

  // lumuto_partition: go through and find greater and then swap
  // small < pivot < large
  // pivot is EXACTLY at index p
  int lomuto_partition(vector<int> &nums, int low, int high) {
    int pivot = nums[high];
    int i = low;

    for (int j = low; j < high; j++) {
      if (nums[j] > pivot) { // order: larger elements to left
        swap(nums[i], nums[j]);
        i++;
      }
    }

    swap(nums[i], nums[high]);
    return i;
  }

public:
  // approach 3: using quick select
  int findKthLargest(vector<int> &nums, int k) {

    int start = 0;
    int end = nums.size() - 1; // its index so
    int target = k - 1;

    // lomuto: where did pivot land ? suitable for quick select
    while (start <= end) {
      int p = lomuto_partition(nums, start, end);

      if (target == p) {
        return nums[p];
      }

      if (target < p) {
        end = p - 1;
      } else {
        start = p + 1;
      }
    }

    return -1;
  }
};

// navie approaches
class SolutionNaive {
public:
  // naive;  solve it with sorting O(nlogn)
  int findKthLargestNaive(vector<int> &nums, int k) {
    sort(begin(nums), end(nums), greater<int>()); // sort in ascending order
    return k - 1 < nums.size() ? nums[k - 1] : INT_MAX;
  }

  // solve; using minheap
  int findKthLargestHeap(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int &num : nums) {
      minHeap.push(num);

      if (minHeap.size() > k) {
        minHeap.pop();
      }
    }

    return minHeap.top();
  }
};
