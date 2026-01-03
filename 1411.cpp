// 1411. Number of Ways to Paint N × 3 Grid
// LeetCode: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
//
// Problem: Given an n × 3 grid, find the number of ways to paint each cell 
// with one of 3 colors (1, 2, 3) such that no adjacent cells have the same color.
// Return the answer modulo 10^9 + 7.
//
// Approach: Dynamic Programming with pattern counting
// - We track two types of row patterns:
//   - ABA: First and last cells have same color (e.g., 1-2-1)
//   - ABC: All three cells have different colors (e.g., 1-2-3)
// - For each new row:
//   - If previous row was ABA (3 colors), next row can be ABA (3 ways) or ABC (2 ways)
//   - If previous row was ABC (6 colors), next row can be ABA (2 ways) or ABC (2 ways)
// - Base case: First row has 6 ABA patterns and 6 ABC patterns
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        
        // Initial count: 6 ways for ABA pattern and 6 ways for ABC pattern
        long long patternABA = 6;
        long long patternABC = 6;
        
        // Process remaining rows (n-1 rows after the first)
        while (--n) {
            // Calculate next row patterns based on current row
            // If current row is ABA: next can be 3 ABA patterns or 2 ABC patterns
            // If current row is ABC: next can be 2 ABA patterns or 2 ABC patterns
            long long nextpatternABA = (patternABA * 3 + patternABC * 2) % MOD;
            long long nextpatternABC = (patternABA * 2 + patternABC * 2) % MOD;
            
            // Update for next iteration
            patternABA = nextpatternABA;
            patternABC = nextpatternABC;
        }
        
        // Return total number of valid colorings
        return (patternABA + patternABC) % MOD;
    }
};