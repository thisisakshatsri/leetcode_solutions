class Solution {
public:
    string reverseWords(string s) {
        while(s[0] == ' '){
            s.erase(s.begin());
        }
        for(int i=0; i<s.size(); i++) {
            if(i+1<s.size() && s[i]==' ' && s[i+1] == ' '){
                s.erase(s.begin()+i);
                i--;
            }
        }  
        reverse(s.begin(), s.end());
        while(s[0] == ' '){
            s.erase(s.begin());
        }
        int start = 0;
        int end = 0;
        while(end<s.size()) {
            if(s[end] == ' '){
            reverse(s.begin()+start, s.begin()+end);
            start = end+1;
            }
            ++end;
        }
        reverse(s.begin()+start, s.end());
        return s;
    }
};