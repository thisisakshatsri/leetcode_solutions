class Solution {
    #define MOD 1000000007
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        //map key( arr[i] ) to value ( as 1 'cause a single value is also counted')
        unordered_map<int, long> map;
        for(auto x: arr) map.insert({x, 1});
        
        //sorted array, because we can search factors backwards linearly. It would become               easy to search
        sort(arr.begin(), arr.end());
        
        //started from 1 'cause at 0th pos there will be no such factors as the array is                sorted
        for(int i=1; i<arr.size(); ++i) {
            long count = 0;
            for(int j=0; j<i; ++j) {
            //if I got one factor by simply check if a[i] % a[j] = 0 then we've to search                 for another value
                //Eg: 4%2 == 0, so for root 4, 2 become one value we need one more 2
                //so we simply find it in our map and the add it to the count
                //so for another value which satisfy condition (left * right = node) 
                //we can find easily by - root / first factor(a[j]);
                if(arr[i] % arr[j] == 0) {
                    if(map.find(arr[i] / arr[j]) != map.end())
                    count += map.find(arr[j])->second * map.find(arr[i] / arr[j])->second;
                }
            }
            map.find(arr[i])->second += count;
        }
        
        long sum = 0;
        for(auto it: map) sum += it.second;
        return sum % MOD;
    }
};