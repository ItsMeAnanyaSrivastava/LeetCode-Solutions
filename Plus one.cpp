/* 
 * LeetCode Problem No. 66 : Plus One
 * Difficulty: Easy
 * 
 * Problem Description:
 * Given a non-empty array of decimal digits representing a non-negative integer,
 * increment one to the integer. The digits are stored such that the most significant
 * digit is at the head of the list, and each element in the array contains a single digit.
 * 
 * Example:
 * Input: digits = [1,2,3]
 * Output: [1,2,4]
 * 
 * Input: digits = [9,9,9]
 * Output: [1,0,0,0]
 * 
 * Time Complexity: O(n) where n is the number of digits
 * Space Complexity: O(1) - in-place modification (O(n) only when all digits are 9)
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int last = digits.size() - 1;
        int carry = 1;
        
        // Quick check: if last digit is less than 9, simply increment and return
        if (digits[last] < 9) {
            digits[last] += 1;
            return digits;
        }
        
        // Handle carry propagation from right to left
        for (int i = last; i >= 0; i--) {
            if (digits[i] == 9) {
                // Current digit is 9, set it to 0 and continue carry
                digits[i] = 0;
                carry = 1;
            } else {
                // Current digit is less than 9, increment and stop
                digits[i] += 1;
                carry = 0;
                break;
            }
        }
        
        // If carry still exists after the loop, all digits were 9
        // Need to add 1 at the beginning (e.g., 999 -> 1000)
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};