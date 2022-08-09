class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        bool dp[size][size];
        string res;
        int maxlength = 0;
        
        for(int gap=0; gap<size; gap++) {
            for(int row=0, col=gap; col<size; row++, col++) {
                if(gap == 0){
                    dp[row][col] = true;
                }
                else if(gap == 1){
                    if(s[row] == s[col])
                        dp[row][col] = true;
                    else dp[row][col] = false;
                }
                else{
                    if(s[row] == s[col] && dp[row+1][col-1] == true)
                        dp[row][col] = true;
                    else dp[row][col] = false;
                }
                if(dp[row][col] == true){
                    if(col - row + 1 > maxlength)
                        maxlength = col - row + 1;
                    res = s.substr(row, maxlength);
                }
            }
        }
        return res;
    }
};