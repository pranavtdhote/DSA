class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(int num:nums){
            freq[num]++;
        }

        vector<pair<int, int>> elements;

        for(auto it : freq){
            elements.push_back({it.second , it.first});
        }

        sort(elements.rbegin(), elements.rend());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(elements[i].second);
        }
        return ans;
    }
};