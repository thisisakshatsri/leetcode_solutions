class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int cnt[256] = {0}, cnt1[256] = {0};
        for(int i=0; i<s.size(); i++){
            if(cnt[s[i]] != cnt1[t[i]])
                return false;
            cnt[s[i]] = i+1;
            cnt1[t[i]] = i+1;
        }
        return true;
    }
};