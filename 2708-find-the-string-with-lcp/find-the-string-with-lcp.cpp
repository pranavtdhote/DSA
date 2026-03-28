class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        // Step 1: validate diagonal + symmetry
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] != lcp[j][i]) return "";
            }
        }

        // Step 2: DSU initialization
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        // Step 3: union positions
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    unite(i, j);
                }
            }
        }

        // Step 4: assign characters
        unordered_map<int, char> mp;
        char ch = 'a';

        string word(n, '?');

        for (int i = 0; i < n; i++) {
            int root = find(i);

            if (!mp.count(root)) {
                if (ch > 'z') return "";
                mp[root] = ch++;
            }
            word[i] = mp[root];
        }

        // Step 5: validate LCP
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] == word[j]) {
                    if (i + 1 < n && j + 1 < n)
                        dp[i][j] = 1 + dp[i + 1][j + 1];
                    else
                        dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }

                if (dp[i][j] != lcp[i][j])
                    return "";
            }
        }

        return word;
    }
};