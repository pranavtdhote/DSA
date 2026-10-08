class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int CurrSum = 0;
        int MaxSum = INT_MIN;
        int maxSumtillNow = INT_MIN;
        int n = nums.size();

        for(int i=0;i<n;i++){
            CurrSum+=nums[i];

            MaxSum = max(CurrSum, MaxSum);

            if(CurrSum<0){
                maxSumtillNow = 0;
                CurrSum = 0;
            }
        }
        return MaxSum;
    }
};