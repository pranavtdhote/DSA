class Solution {
public:
    int numSub(string s) {
     int mod = 1e9 + 7;
     int count = 0;
     long long ans = 0;

     for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                count++;
                ans = (ans + count) % mod;
            }
            else {
                count = 0;
            }
        }
        return ans;
    }
};