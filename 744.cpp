/**
 * LeetCode 744: Find Smallest Letter Greater Than Target
 * 
 * Problem: Given a sorted array of characters letters and a character target,
 * find the smallest character in letters that is lexicographically greater than target.
 * Letters wrap around - if no such character exists, return the first character.
 * 
 * Example:
 * Input: letters = ["c","f","j"], target = "a"
 * Output: "c"
 * 
 * Input: letters = ["c","f","j"], target = "c"
 * Output: "f"
 * 
 * Time Complexity: O(n) - linear search through the array
 * Space Complexity: O(1) - constant extra space
 */
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // Convert target character to its ASCII value
        int at=static_cast<int>(target);
        
        // Iterate through all letters to find the first one greater than target
        for (int i=0;i<letters.size();i++){
            // Convert current letter to its ASCII value
            int l=static_cast<int>(letters[i]);
            
            // If current letter is greater than target, return it
            if (l>at){
                return letters[i];
            }
        }
        
        // If no letter is greater than target, wrap around and return the first letter
        return letters[0];
    }
};