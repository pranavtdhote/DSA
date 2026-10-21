class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);

        int l=0;
        int r=n-1;
        int i=n-1;
        while(l<=r){
            if(nums[l]*nums[l]<nums[r]*nums[r]){
                result[i]=nums[r]*nums[r];
                r--;
            }else{
                result[i]=nums[l]*nums[l];
                l++;
            }
            i--;
        }
        return result;
    }
};