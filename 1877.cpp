#include <algorithm>
#include <vector>

// LeetCode 1877: Minimize Maximum Pair Sum in Array
// Greedy: after sorting, pair smallest with largest so every element is used once
// and the maximum pair sum is minimized.
// Sorting dominates runtime: O(n log n) time, O(1) extra space beyond sort.
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int ans=0;
        while(i<j){
            ans=max(ans,nums[i]+nums[j]);
            i++;
            j--;
        }
        return ans;
    }
};