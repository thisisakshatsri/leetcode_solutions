class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        int k = pow(3, 19);
        if(k % n == 0)
            return true;
        return false;
    }
};