class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int currsum = 0;
        
        for(int i=0; i<nums.size(); i++) {
            currsum = max(currsum + nums[i] , nums[i]);
            maxsum  = max(maxsum , currsum);
        }
        return maxsum;
    }
};