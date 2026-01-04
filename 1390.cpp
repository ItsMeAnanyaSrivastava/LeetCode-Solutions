//1390 Four Divisors
// Given an integer array nums, return the sum of divisors of the integers
//  in that array that have exactly four divisors. 
// If there is no such integer in the array, return 0.
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int n : nums) {
            int count = 0, sum = 0;
            for (int j = 1; j * j <= n; j++) {
                if (n % j == 0) {
                    // j is a divisor; add both j and its pair n/j when distinct
                    count++;
                    sum += j;
                    if (j != n / j) {   
                        count++;
                        sum += n / j;
                    }
                    if (count > 4) break;
                }
            }
            if (count == 4)
                ans += sum;
        }
        return ans;
    }
};
 