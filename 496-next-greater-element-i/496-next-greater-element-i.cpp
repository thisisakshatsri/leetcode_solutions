class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        stack<int> s;
        int n = nums2.size();
        
        for(int i = n-1; i>=0; i--) {
            if(s.size() == 0) v.push_back(-1);
            else if(s.size() > 0 && s.top() > nums2[i]) v.push_back(s.top());
            else if(s.size() > 0 && s.top() <= nums2[i]){
                while(s.size() > 0 && s.top() <= nums2[i]) {
                    s.pop();
                }
                if(s.size() == 0) v.push_back(-1);
                else v.push_back(s.top());
            }
            s.push(nums2[i]);
        }
        reverse(v.begin(), v.end());
        
        vector<int> res;
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    res.push_back(v[j]);
                }
            }
        }
        return res;
    }
};