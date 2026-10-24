class Solution {
public:
    int sumOfDigit(int n){
        int sum = 0;
        while(n>0){
            int digit = n % 10;
            sum+=digit;
            n/=10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
       int minSum = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(sumOfDigit(nums[i])<minSum){
                minSum = sumOfDigit(nums[i]);
            }
        }
        return minSum;
    }
};