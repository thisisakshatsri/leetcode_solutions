class Solution {
public:
    //MAH Function
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
    int MAH(vector<int>& heights) {
        return largestArea(heights);
    }
//End of MAH function
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> histogram(m, 0);

        
        vector<vector<int> > mat(n, vector<int>(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                mat[i][j] = int(matrix[i][j]-'0');
        
        
        for(int j=0; j<m; j++){
            histogram[j] = mat[0][j];
        }
        
        res = MAH(histogram);
        cout<<res<<" ";
        
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1) 
                    histogram[j] += 1;
                else 
                    histogram[j] = 0;
            }
            res = max(res, MAH(histogram));
        }
        return res;
    }
};

/*
PreRequisite:  MAH -> 84.Maximum Area of Histogram

Algorithm Outline:
largestArea()

        |
    |   |       |
|   |   |   |   |

1   2   3   1   2   -> 5
0   1   2   3   4   -> index

MAH Function gives the area of largest possible rectangle

main()
1. Calculate histogram array for each row
2. Check largest area in that row by using MAH function
3. Return ans


Horizontal - can check length
Verticle - Keep height of each column top to bottum

calculate area for each histogram in each row 

1 0 1 0 0   -> 1  ans = 1
1 0 1 1 1   -> 3  ans = 3
1 1 1 1 1   -> 6  ans = 6
1 0 1 1 1   -> 4  ans = 6

*/