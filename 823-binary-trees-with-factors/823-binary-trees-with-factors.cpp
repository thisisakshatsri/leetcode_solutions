class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, long> map;
        sort(arr.begin(), arr.end());
        for(auto x: arr){
            map.insert({x, 1});
        }
        
        long sum = 0;
        
        for(int i=1; i<arr.size(); i++) {
            long count = 0;
            for(int j=0; j<i; j++){
                if(arr[i] % arr[j] == 0){
                    if(map.find(arr[i]/arr[j]) != map.end()){
                        count += map.find(arr[j])->second * map.find(arr[i]/arr[j])->second;
                    }
                }
            }
            map.find(arr[i])->second += count;
        }
        
        for(auto it: map){
            sum += it.second;
        }
        return sum % 1000000007;
    }
};