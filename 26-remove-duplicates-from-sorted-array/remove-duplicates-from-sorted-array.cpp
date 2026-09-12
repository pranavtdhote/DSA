class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) return 0;
        
        int count = 1;
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                count++;
            }
        }

        vector<int> arr2(count);
        
        cout << count << endl;
        
        arr2[0] = nums[0];
        
        int j = 1;
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                arr2[j] = nums[i + 1];
                j++;
            }
        }
        
        for (int i = 0; i < count; i++) {
            nums[i] = arr2[i];
        }
        
        return count;
    }
};