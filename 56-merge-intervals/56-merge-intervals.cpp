class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        
        int j=0;
        int k=0;
        for(int i=1; i<intervals.size(); i++) {
            vector<int> v;
            if(ans[j][1] >= intervals[i][0]) {
                ans[j][1] = max(intervals[i][1], ans[j][1]);
            }
            
            else {
                j++;
                ans.push_back(intervals[i]);    
            }
            
        }
        return ans;
    }
};