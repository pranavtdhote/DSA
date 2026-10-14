class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num){
            return "";
        }

        string result = "";

        while(num>0){
            int digit = min(9,sum);
            result+=char('0'+ digit);
            sum-=digit;
            num--;
        }
        return result;
    }
};