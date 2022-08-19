class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        
        int temp = 1;
        int pro = 1;
        for(int i=0; i<n; i++){
            v.emplace_back(temp);
            temp *= nums[i];
        }
        
        temp = 1;
        
        for(int i=n-1; i>=0; i--) {
            v[i]*=temp;
            temp*=nums[i];
        }
        return v;
    }
};