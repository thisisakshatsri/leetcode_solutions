class Solution {
public:
    vector<int> sol(string s) {
        unordered_map<char, int> m;
        vector<int> x;
        int a = 0;
        for(int i=0; i<s.size(); i++) {
            if(m.find(s[i]) == m.end()){
                m[s[i]] = a++;
                x.push_back(m[s[i]]);
            }
            else x.push_back(m[s[i]]);
        }
        return x;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        vector<int> pat;
        pat = sol(pattern);
        for(int i=0; i<words.size(); i++) {
            vector<int> v;
            v = sol(words[i]);
            if(v == pat) res.push_back(words[i]);
        }
        return res;
    }
};