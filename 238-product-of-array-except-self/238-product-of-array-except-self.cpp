class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() == 0) return{0};
        int len = nums.size();
        vector<int> res(len);
        int temp = 1;
        
        for(int i=0; i<len; i++) {
            res[i] = temp;
            temp *= nums[i];
        }
        
        temp = 1;
        
        for(int i=len-1; i>=0; i--) {
            res[i] *= temp;
            temp *= nums[i];
        }
        return res;
    }
};