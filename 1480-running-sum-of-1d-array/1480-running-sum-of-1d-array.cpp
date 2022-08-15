class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> v;
        int res = 0;
        for(int i=0; i<nums.size(); i++) {
            res = res+nums[i];
            v.push_back(res);
        }
        return v;
    }
};