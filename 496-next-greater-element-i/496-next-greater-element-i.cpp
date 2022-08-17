class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        stack<int> s;
        int n = nums2.size();
        unordered_map<int, int> mp;

        for(int i = n-1; i>=0; i--) {
            while(!s.empty() && s.top() <= nums2[i] ) {
                s.pop();
            }
            int res = (s.empty()) ? -1 : s.top();
            
            mp.insert({nums2[i], res});
            s.push(nums2[i]);
        }
        
        vector<int> res;
        for(auto x: nums1) {
            res.push_back(mp[x]);
        }
        return res;
    }
};