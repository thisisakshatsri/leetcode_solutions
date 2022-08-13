class Solution {
    public int kthGrammar(int n, int k) {
        
        if(n == 1 && k == 1){
            return 0;
        }
        
        double mid = Math.pow(2 , n - 1) / 2;
        
        int middle = (int)mid; //typecasting
        
        int m;

        if(k <= middle)
            return kthGrammar(n - 1 , k);
        else{
            if(kthGrammar(n - 1 , k - middle) == 0)
                return 1;
            else return 0;
        }
    }
}