// 961. N-Repeated Element in Size 2N Array
// LeetCode: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
//
// Problem: Given an array of size 2n containing n+1 unique elements where one element 
// appears exactly n times, find and return that repeated element.
//
// Approach: Linear Search with Counting
// - Iterate through each element in the array
// - Count occurrences of each element using std::count
// - When an element appears n times (size/2), return it
//
// Note: Since one element must appear n times out of 2n elements, we can guarantee 
// to find it by the time we've checked all elements.
//
// Time Complexity: O(n^2) - Counting each element takes O(n) and we do it for each element
// Space Complexity: O(1) - Only using constant extra space

#include <algorithm>

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // Iterate through each element in the array
        for (auto i : nums) {
            // Count how many times the current element appears in the array
            int count = std::count(nums.begin(), nums.end(), i);
            
            // If this element appears n times (which equals size/2 for a 2n array)
            if (count == (nums.size()) / 2) {
                return i;  // Found the repeated element
            }
        }
        
        // This line should never be reached given valid input
        return -1;
    }
};