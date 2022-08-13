class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        if(sentences.size() == 0) return 0;
        
        int ans = 0;
        int n = sentences.size();
        
        for(int i=0; i<n; i++){
            int space = 0;
            for(int j=0; j<sentences[i].size(); j++) {
                if(sentences[i][j] == ' ') space++;
            }
            ans = max(ans, space);
        }
        return ans+1;
    }
};