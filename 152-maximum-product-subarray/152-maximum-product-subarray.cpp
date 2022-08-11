class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //empty array case
        if(nums.size() == 0 ) return 0;
        
        //To store the max and min product
        int maxSub = nums[0];
        int minSub = nums[0];
        int maxProduct = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
            //Swapping max and min
            //Because, when multiplying negative number with a negative number number becomes positive, so the minimum negative number will be the maximum number
            if(nums[i] < 0) {
                swap(maxSub, minSub);
            }
            //Update all the sub values
            maxSub = max(maxSub * nums[i] , nums[i]);
            minSub = min(minSub * nums[i] , nums[i]);
            //Update maxProduct
            maxProduct = max(maxProduct, maxSub);
        }
        return maxProduct;
    }
};