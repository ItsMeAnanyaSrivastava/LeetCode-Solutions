// LeetCode 1975: Maximum Matrix Sum
// Difficulty: Medium
// 
// Problem: Given an n x n matrix, you can perform operations where you select any two adjacent 
// elements and multiply both by -1. Return the maximum sum of the matrix's elements after 
// performing any number of operations.
//
// Key Insight: Adjacent elements can pass negative signs between them. If there's an even number
// of negatives, we can eliminate all of them. If odd, we're stuck with one negative, and we want
// it on the smallest absolute value element.
//
// Time Complexity: O(n²) - we iterate through all matrix elements once
// Space Complexity: O(1) - only using constant extra space

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // Sum of absolute values of all elements
        long long sum = 0;
        
        // Count of negative numbers in the matrix
        int neg = 0;
        
        // Track the minimum absolute value in the matrix
        int min_abs = INT_MAX;
        
        // Iterate through all elements in the matrix
        for (auto i: matrix) {
            for (int j: i) {
                // Add absolute value to sum
                sum += abs(j);
                
                // Count negative numbers
                if (j < 0) {
                    neg++;
                }
                
                // Track the smallest absolute value
                min_abs = min(min_abs, abs(j));
            }
        }
        
        // If odd number of negatives, we must keep one negative
        // Place it on the element with smallest absolute value
        if (neg % 2 != 0) {
            return sum - 2 * min_abs;
        }
        
        // If even number of negatives, we can eliminate all of them
        return sum;
    }
};