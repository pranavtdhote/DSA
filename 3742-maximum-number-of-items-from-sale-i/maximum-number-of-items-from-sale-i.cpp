class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> factor(n), price(n), freeCnt(n, 0);

        // Extract factors and prices
        for (int i = 0; i < n; i++) {
            factor[i] = items[i][0];
            price[i] = items[i][1];
        }

        // Calculate free copies for each item type
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && factor[j] % factor[i] == 0) {
                    freeCnt[i]++;
                }
            }
        }

        const int NEG = -1e9;

        // dp[b] = maximum copies after activation,
        // using exactly b budget
        vector<int> dp(budget + 1, NEG);

        dp[0] = 0;

        // Phase 1: 0/1 Knapsack for activating item types
        for (int i = 0; i < n; i++) {
            int cost = price[i];
            int gain = 1 + freeCnt[i];

            for (int b = budget; b >= cost; b--) {
                if (dp[b - cost] != NEG) {
                    dp[b] = max(dp[b],
                              dp[b - cost] + gain);
                }
            }
        }

        // Phase 2: Unbounded Knapsack for extra copies
        for (int i = 0; i < n; i++) {
            int cost = price[i];

            for (int b = cost; b <= budget; b++) {
                if (dp[b - cost] != NEG) {
                    dp[b] = max(dp[b],
                    dp[b - cost] + 1);
                }
            }
        }

        // We can spend at most budget
        int ans = 0;

        for (int b = 0; b <= budget; b++) {
            ans = max(ans, dp[b]);
        }

        return ans;
    }
};