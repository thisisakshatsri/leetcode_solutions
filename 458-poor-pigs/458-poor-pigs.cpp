class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int totaltest = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(totaltest));
    }
};