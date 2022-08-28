class Solution {
public:
    void countSort(vector<vector<int>> &mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        
        int i = r;
        int j = c;
        vector<int> count;
        
        while(i<n && j<m) {
            count.push_back(mat[i][j]);
            i++;
            j++;
        }
        
        sort(count.begin(), count.end());
        i=r;
        j=c;
        for(auto x: count){
            mat[i][j] = x;
            i++;
            j++;
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0; i<n; i++) {
            countSort(mat, i, 0);
        }
        
        for(int j=0; j<m; j++) {
            countSort(mat, 0, j);
        }
        return mat;
    }
};