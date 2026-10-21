class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int CurrSum = 0;
        int MaxSum = 0;

        for(int i=0;i<k;i++){
            CurrSum+=nums[i];
        }
        MaxSum = CurrSum;
        for(int i=k;i<nums.size();i++){
            CurrSum = CurrSum - nums[i-k] + nums[i];
            MaxSum = max(CurrSum,MaxSum);
        }
        return (double) MaxSum/k;
    }
};