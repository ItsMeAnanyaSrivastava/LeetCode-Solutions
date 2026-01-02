//961. N-Repeated Element in Size 2N Array
#include <algorithm>
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for (auto i : nums) {
            int count = std::count(nums.begin(), nums.end(), i);
            if (count == (nums.size()) / 2) {
                return i;
            }
        }
        return -1;
    }
};