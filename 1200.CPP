class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // Sort to ensure the minimum absolute difference occurs between neighbors
        sort(arr.begin(),arr.end());
        int mini=INT_MAX;
        vector<vector<int>>ans;
        for (int i=0;i<arr.size()-1;i++){
            // Track the smallest adjacent difference found so far
            mini=min(arr[i+1]-arr[i],mini);
        }
        for (int i=0;i<arr.size()-1;i++){
            // Collect all pairs that achieve the minimum difference
            if (arr[i+1]-arr[i]==mini){
                vector<int> temp={arr[i],arr[i+1]};
                ans.push_back(temp);
            }
        }
        return ans;
    }
};