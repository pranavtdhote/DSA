class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin() , nums.end());
        int curr = nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=curr){
                res.push_back(curr);
                i--; 
            }
            curr++;
        }
        return res;
    }
};