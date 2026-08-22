class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int r = n;
        while(n>0){
            int d = n % 10;
            sum += d;
            prod *= d;
            n = n/10;
        }
        return r % (sum + prod) == 0;
    }
};