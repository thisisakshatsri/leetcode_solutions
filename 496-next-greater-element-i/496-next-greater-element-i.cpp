class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        stack<int> s;
        int n = nums2.size();
        unordered_map<int, int> mp;
        
        
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
        for(int i=0; i<v.size(); i++) {
            mp[nums2[i]] = v[i];
        }
        vector<int> res;
        for(auto x: nums1) {
            res.push_back(mp[x]);
        }
        return res;
    }
};