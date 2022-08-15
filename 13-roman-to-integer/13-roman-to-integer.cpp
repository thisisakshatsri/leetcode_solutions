class Solution {
public:
    int romanToInt(string str) {
        int number = 0;
        
        unordered_map<char,int> map {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        
        for(int i = 0; i < str.size(); i++) {
            if (map[str[i]] < map[str[i + 1]])
                number -= map[str[i]];
            else
                number += map[str[i]];
        }
        return number;
    }
};