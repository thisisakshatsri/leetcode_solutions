class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> v;
        stack<int> s;
        int n = nums.size();
        
        for(int i=n-1; i>=0; i--) {
            if(s.size() == 0) v.push_back(-1);
            else if(s.size() > 0 && s.top() > nums[i]) v.push_back(s.top());
            else if(s.size() > 0 && s.top() <= nums[i]) {
                while(s.size() > 0 && s.top() <= nums[i]){
                    s.pop();
                }
                if(s.size() == 0) v.push_back(-1);
                else v.push_back(s.top());
            }
            s.push(nums[i]);
        }
        v.erase(v.begin(), v.end());
        for(int i=n-1; i>=0; i--) {
            if(s.size() == 0) v.push_back(-1);
            else if(s.size() > 0 && s.top() > nums[i]) v.push_back(s.top());
            else if(s.size() > 0 && s.top() <= nums[i]) {
                while(s.size() > 0 && s.top() <= nums[i]){
                    s.pop();
                }
                if(s.size() == 0) v.push_back(-1);
                else v.push_back(s.top());
            }
            s.push(nums[i]);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};