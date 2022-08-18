class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        vector<int> freq;
        
        for(int nums : arr){
            mp[nums]++;
        }
        
        for(auto x: mp){
            freq.emplace_back(x.second);
        }
        sort(freq.begin(), freq.end(), greater<int>());
        
        
        int sum = 0;
        int cnt = 0;
        for(int i: freq){
            sum += i;
            cnt++;
            if(sum >= n/2)
                break;
        }
        return cnt;
    }
};