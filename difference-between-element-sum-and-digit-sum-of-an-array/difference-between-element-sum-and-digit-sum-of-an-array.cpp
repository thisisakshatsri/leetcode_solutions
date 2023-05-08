class Solution {
public:
    int sum(int n) {
        int res = 0;
        while(n) {
            res += n%10;
            n /= 10;
        }
        return res;
    }
    int differenceOfSum(vector<int>& nums) {
        int elesum = 0, digisum = 0;
        for(auto i : nums) {
            elesum += i;
            digisum += sum(i);
        }
        return abs(elesum - digisum);
    }
};