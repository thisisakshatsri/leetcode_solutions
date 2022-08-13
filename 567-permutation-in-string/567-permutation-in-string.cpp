class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int cnt[26] = {0};
        for(int i=0; i<s1.length(); i++) {
            cnt[s1[i]-'a']++;
        }
        
        int i=0, j=0, res = s1.size();
        
        while(j < s2.size()) {
            if(cnt[s2[j++]-'a']-- > 0) {
                res--;
            }
            if(res == 0)
                return true;
            if(j - i == s1.size() && cnt[s2[i++]-'a']++ >= 0){
                res++;
            }
        }
        return false;
    }
};