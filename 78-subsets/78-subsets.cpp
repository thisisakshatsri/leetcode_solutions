class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &subset, int i, vector<int> &nums) {
        if(i == nums.size()){
            ans.push_back(subset);
            return;
        }
        //ith element in subset
        solve(subset, i+1, nums);
        //ith element not in subset
        subset.push_back(nums[i]);
        solve(subset, i+1, nums);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> empty;
        solve(empty, 0, nums);
        return ans;
    }
};