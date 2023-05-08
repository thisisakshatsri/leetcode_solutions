class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        if(mat.size() == 0) return 0;
        
        int n = mat.size();
        int m = mat[0].size();
        int left = 0;
        int right = 0;
        
        for(int i=0, j=0; j<m; i++, j++) {
            left += mat[i][j];
        }
        
        for(int i=0, j=m-1; j>=0; i++, j--){
            right += mat[i][j];
        }
        if(n %2 != 0){
        int midrow = n/2;
        int lo = 0, hi = mat[midrow].size() - 1;
        int mid = lo + (hi - lo) / 2;
        int midEle = mat[midrow][mid];
        return left+right - midEle;
        }
        return left + right;
    }
};