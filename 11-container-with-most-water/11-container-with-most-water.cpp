class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 0) return 0;
        
        int n = height.size();
        int start = 0;
        int end = n-1;
        int maxarea = 0;
        while(start < end) {
            int area = min(height[start], height[end]) * (end - start);
            if(area > maxarea) maxarea = area;
            else if(min(height[start] , height[end]) == height[start]){
                start++;
            }
            else{
                end--;
            }
        }
        return maxarea;
        
    }
};