class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) mp[nums[i]]++;
        int res = 0;
        int ans = 0;
        for(auto x : mp) {
            if(x.second > res){
                res = x.second;
                ans = x.first;
            }            
        }
        return ans;
    }
};