class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxele = INT_MIN;
        int moves = 0;
        sort(nums.begin(),nums.end());
        for(int x:nums){
            maxele = max(maxele , x);
        }
        for(int x:nums){
            moves+=maxele-x;
        }
        return moves;
    }
};