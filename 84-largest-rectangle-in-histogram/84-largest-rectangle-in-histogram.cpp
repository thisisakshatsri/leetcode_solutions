class Solution {
public:
    //The Solution is breakdown in 4 parts.
    //Part one:     Calculate Index of Nearest Smaller to left
    //Part two:     Calculate Index of Nearest Smaller to right
    //Part three:   Calculate Width using :: right[i] - left[i] - 1
    //Part four:    Calculate Area and update MaxArea
    
//----------------------For Reference:: Aditya Verma----------------------------------------
    
    //Part 1
    vector<int> prevSmall(vector<int> arr) {
        vector<int> v;
        stack<pair<int, int>> s;
        
        for(int i = 0; i < arr.size(); i++) {
            if(s.size() == 0) v.push_back(-1);
            else if(s.size() > 0 && s.top().first < arr[i]) v.push_back(s.top().second);
            else if(s.size() > 0 && s.top().first >= arr[i]) {
                while(s.size() > 0 && s.top().first >= arr[i]) {
                    s.pop();
                }
                if(s.size() == 0) v.push_back(-1);
                else v.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }
        return v;
    }
   //Part 2 
    vector<int> nextSmall(vector<int> arr) {
        vector<int> v;
        stack<pair <int, int>> s;
        int pi = arr.size();
        
        for(int i = arr.size() - 1; i >= 0; i--) {
            if(s.size() == 0) v.push_back(pi);
            else if(s.size() > 0 && s.top().first < arr[i]) v.push_back(s.top().second);
            else if(s.size() > 0 && s.top().first >= arr[i]) {
                while(s.size() > 0 && s.top().first >= arr[i]){
                    s.pop();
                }
                if(s.size() == 0) v.push_back(pi);
                else v.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }
        reverse(v.begin(), v.end());
        return v;
    }
    
    //Part 3
    int largestArea(vector<int> arr) {
        vector<int> left = prevSmall(arr);
        vector<int> right = nextSmall(arr);
        int maxArea = INT_MIN;
        
        for(int i = 0; i < arr.size(); i++) {
            int length = arr[i];
            int breadth = right[i] - left[i] - 1;
            int newArea = length * breadth;
            //Part 4
            maxArea = max(maxArea, newArea);
        }
        return maxArea;
    }
    int largestRectangleArea(vector<int>& heights) {
        return largestArea(heights);
    }
};