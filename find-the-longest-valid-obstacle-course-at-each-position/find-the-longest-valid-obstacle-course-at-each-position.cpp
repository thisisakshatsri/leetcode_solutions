class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
         vector<int> dp (obstacles.size(),1);
         vector<int> temp(obstacles.size()+1, 1e9+7);
         temp[0] = -1e9+7;
         int res = 1;
        for(int i=0; i<obstacles.size(); i++){
            int j = upper_bound(temp.begin(), temp.end(), obstacles[i]) - temp.begin();
            temp[j] = obstacles[i];
            dp[i] = j;
        }
        return dp;
    }
};