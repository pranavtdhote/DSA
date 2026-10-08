class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix = 0;
        int count = 0;

        for(int i = 0; i < n; i++) {
            prefix = 0;

            for(int j = i; j < n; j++) {
                prefix += nums[j];

                if(prefix == k) {
                    count++;
                }
            }
        }

        return count;
    }
};