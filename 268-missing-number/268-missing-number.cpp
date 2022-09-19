class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        if(n == 1){
            if(nums[0] == 0)
                return 1;
            else if(nums[0] == 1)
                return 0;
        }
        if(n == 2) {
            if(nums[0] == 0 && nums[1] == 1)
                return 2;
        }
        for(int i=0; i<n; i++) {
            if(nums[i] != i) return i;
        }
        return n;
    }
};