class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        if(target == 0) return 0;
        if(startFuel < target && n > 0 && startFuel < stations[0][0]) return-1;
        
        int totalFuel = 0, currentStation = 0, count = 0;
        priority_queue<int> pq;
        pq.push(startFuel);
        
        while(!pq.empty()) {
            int current = pq.top(); pq.pop();
            totalFuel += current;
            
            if(totalFuel >= target) return count;
            while(currentStation < n && totalFuel >= stations[currentStation][0]){
                pq.push(stations[currentStation][1]);
                currentStation++;
            } 
            count++;
        }
        return -1;
    }
};