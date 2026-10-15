class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int SquareSum = 0;

        for(int i=0;i<n;i++){
            unordered_set<int> sub;
            for(int j=i;j<n;j++){
                sub.insert(nums[j]);

                int m = sub.size();
                SquareSum+=m*m;
            }
        }
        return SquareSum;
    }
};