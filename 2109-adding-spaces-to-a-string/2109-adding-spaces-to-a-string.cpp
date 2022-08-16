class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        //APPROACH
        int len = s.length() + spaces.size();
        string ans (len, '#');
        int k=0;
        for(int i=0; i<spaces.size(); i++) {
            ans[spaces[i]+k] = ' ';
            k++;
        }
        int j=0;
        for(int i=0; i<ans.length(); i++) {
            if(ans[i] == '#'){
                ans[i] = s[j++];
            }
        }
        return ans;
    }
};