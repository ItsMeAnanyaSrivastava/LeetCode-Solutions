/*
LeetCode 1984 — Minimum Difference Between Highest and Lowest of K Scores

Problem:
Given an array of student scores and an integer k, pick k scores such that
the difference between the highest and lowest selected scores is minimized.

Approach:
1) Sort the scores in non-decreasing order.
2) Use a sliding window of length k over the sorted array. For each window
   starting at index i, the difference is nums[i + k - 1] - nums[i].
3) Track the minimum difference across all valid windows.

Correctness intuition:
Sorting places close scores adjacent, so the best k-group will be contiguous
in the sorted order. Checking all length-k windows guarantees we find the
minimum possible spread.

Complexity:
- Time: O(n log n) due to sorting, plus O(n) for the scan.
- Space: O(1) extra (sorting in-place is allowed in LeetCode environment).
*/
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // Edge case: if k == 1, the minimum difference is always 0
        // (any single score has zero spread). The general logic below covers this.

        // Step 1: sort scores to make close values adjacent
        sort(nums.begin(), nums.end());

        // Step 2: scan all size-k windows and keep the minimal spread
        int ans = INT_MAX;
        for (int i = 0; i <= static_cast<int>(nums.size()) - k; i++) {
            // Current window: [i, i + k - 1]
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }

        // Step 3: return the best found spread
        return ans;
    }
};